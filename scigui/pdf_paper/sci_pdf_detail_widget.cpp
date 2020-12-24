#include "sci_pdf_detail_widget.h"

#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>

#include "scisl/sci_sl_file_visitor_adaptor.h"

sci_pdf_detail_widget::sci_pdf_detail_widget(scicore::sci_pdf_paper* paper,QWidget *parent) : QWidget(parent),_paper(paper) {

    detailItem = QStringList{"题目", "作者", "关键词", "来源", "日期", "被引", "文章编号", "摘要"};

    detialItemData<<QString::fromStdString(_paper->title);
    std::string authors;
    for(int i =0;i<_paper->authors.size();i++){
        authors+=_paper->authors[i]+"$%";
    }
    detialItemData<<QString::fromStdString(authors);
    std::string key_words;
    for(int i =0;i<_paper->key_words.size();i++){
        key_words+=_paper->key_words[i]+"$%";
    }
    detialItemData<<QString::fromStdString(key_words);
    detialItemData<<QString::fromStdString(_paper->origin);
    detialItemData<<QString::fromStdString(_paper->date);
    detialItemData<<QString::number(_paper->citation_times);
    detialItemData<<QString::fromStdString(_paper->id);
    detialItemData<<QString::fromStdString(_paper->abstract);


    QFont detailFont;
    detailFont.setPointSize(14);

    detailButton = new QPushButton(tr("信息"));
    detailButton->setFont(detailFont);
    setButtonStyleSheet(detailButton);
    connect(detailButton, SIGNAL(clicked()), this, SLOT(showDetail()));

    tagButton = new QPushButton(tr("标签"));
    tagButton->setFont(detailFont);
    setButtonStyleSheet(tagButton);
    connect(tagButton, SIGNAL(clicked()), this, SLOT(showTag()));

    webButton = new QPushButton(tr("网络"));
    webButton->setFont(detailFont);
    setButtonStyleSheet(webButton);
    connect(webButton, SIGNAL(clicked()), this, SLOT(showWeb()));

    QHBoxLayout* rightButtonLayout = new QHBoxLayout;
    rightButtonLayout->addStretch();
    rightButtonLayout->addWidget(detailButton);
    rightButtonLayout->addWidget(tagButton);
    rightButtonLayout->addWidget(webButton);
    rightButtonLayout->addStretch();


    // detailTableView
    detailTableView = new QTableView(this);
    QFont detailTableFont;
    detailTableFont.setPointSize(14);
    detailTableView->setFont(detailTableFont);
    detailTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // detailTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // detailTableView->setShowGrid(false);
    //detailTableView->setSelectionMode(QAbstractItemView::NoSelection);
    //detailTableView->setFocusPolicy(Qt::NoFocus);
    //detailTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    detailTableView->horizontalHeader()->hide();
    detailTableView->verticalHeader()->hide();
    detailTableView->setAlternatingRowColors(true);
    detailTableView->setStyleSheet("QTableView{border:0px;background-color:white;alternate-background-color:azure}");

    detailTableModel = new QStandardItemModel(detailTableView);
    detailTableModel->setColumnCount(2);
    detailTableModel->setRowCount(41);

    detailTableView->setModel(detailTableModel);

    QFont f;
    f.setWeight(QFont::Bold);
    for (int i = 0; i < detailItem.size(); i++) {
        QStandardItem* a = new QStandardItem(detailItem[i]);
        a->setFont(f);
        a->setEditable(false);
        a->setData(detailItem[i], Qt::ToolTipRole);
        detailTableModel->setItem(i, 0, a);
        detailTableModel->setItem(i, 1, new QStandardItem(detialItemData[i]));
    }
    connect(detailTableModel,SIGNAL(itemChanged(QStandardItem *)),this,SLOT(change_info(QStandardItem*)));

    // tagView
    tagView = new QListView(this);
    tagView->setFont(detailFont);
    tagView->setSelectionMode(QAbstractItemView::NoSelection);
    tagView->setFocusPolicy(Qt::NoFocus);
    tagView->setStyleSheet("background-color:white;border:0px");
    tagView->hide();

    tagModel = new QStandardItemModel(tagView);
    tagView->setModel(tagModel);

    // example
    QStandardItem* tag = new QStandardItem(tr("Tag"));
    tagModel->appendRow(tag);
    // example


    // webView
    webView = new QListView(this);
    webView->setFont(detailFont);
    webView->setSelectionMode(QAbstractItemView::NoSelection);
    webView->setFocusPolicy(Qt::NoFocus);
    webView->setStyleSheet("background-color:white;border:0px");
    webView->hide();

    webModel = new QStandardItemModel(webView);
    webView->setModel(webModel);

    // example
    QStandardItem* web = new QStandardItem(tr("Web"));
    webModel->appendRow(web);
    // example


    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(6);
    mainLayout->setMargin(0);
    mainLayout->addLayout(rightButtonLayout, 0);
    mainLayout->addWidget(detailTableView, 1);
    mainLayout->addWidget(tagView);
    mainLayout->addWidget(webView);

    setLayout(mainLayout);
}

void sci_pdf_detail_widget::setButtonStyleSheet(QPushButton *b) {
    b->setStyleSheet("QPushButton{padding:2px 22px; background-color:white; color:black; border-radius:10px; border:2px groove gray; border-style:outset;}"
                     "QPushButton:hover{background-color:black; color: white;}"
                     "QPushButton:pressed{background-color:rgb(133, 133, 133); border-style: inset; }"
                     );
}

void sci_pdf_detail_widget::showDetail() {
    qDebug("showDetail");

    tagView->hide();
    webView->hide();

    //detailTableHeaderLabel->show();
    detailTableView->show();
}

void sci_pdf_detail_widget::showTag() {
    qDebug("showTag");

    //detailTableHeaderLabel->hide();
    detailTableView->hide();
    webView->hide();

    tagView->show();
}

void sci_pdf_detail_widget::showWeb() {
    qDebug("showWeb");

    //detailTableHeaderLabel->hide();
    detailTableView->hide();
    tagView->hide();

    webView->show();
}

void sci_pdf_detail_widget::change_info(QStandardItem* item){
    /*QStringList currentData;
     *
    for(int i = 0; i< detialItemData.size() ;i++){
        currentData<<detailTableModel->item(i,1)->text();
    }


    if(detialItemData!=currentData){
        qDebug()<<"currentData"<<currentData;
        switch( QMessageBox::information( this, tr("保存"),QString::fromStdString("文件"+_paper->get_name()+"已修改，是否保存并退出？"),tr("是"),tr("否"), tr("取消"),0, 1 ) )
         {
            case 0:{
            _paper->title = currentData[0].toStdString();
            QStringList authors = currentData[1].split("$%");
            _paper->authors.clear();
            for(int i =0;i<authors.size();i++){
                _paper->authors.push_back(authors[i].toStdString());
            }
            QStringList key_words = currentData[2].split("$%");;
            _paper->key_words.clear();
            for(int i =0;i<key_words.size();i++){
                _paper->key_words.push_back(key_words[i].toStdString());
            }
            _paper->origin = currentData[3].toStdString();
            _paper->date = currentData[4].toStdString();
            _paper->citation_times = currentData[5].toInt();
            _paper->id = currentData[6].toStdString();
            _paper->abstract = currentData[7].toStdString();

            *close = true;
                  break;
            }

        case 1:{
            //event->accept();
            *close = true;
            break;
            }
         default:
            *close = false;
            //event->ignore();
            break;
            }
    }*/
    if(!item){
        return;
    }
    int row = item->row();
    switch (row) {
    case 0:{
        _paper->title = item->text().toStdString();
        break;
    }
    case 1:{
        QStringList authors = item->text().split("$%");
        _paper->authors.clear();
        for(int i =0;i<authors.size();i++){
            _paper->authors.push_back(authors[i].toStdString());
        }
        break;
    }
    case 2:{
        QStringList key_words = item->text().split("$%");;
        _paper->key_words.clear();
        for(int i =0;i<key_words.size();i++){
            _paper->key_words.push_back(key_words[i].toStdString());
        }
        break;
    }
    case 3:{
        _paper->origin = item->text().toStdString();
        break;
    }
    case 4:{
        _paper->date = item->text().toStdString();
        break;
    }
    case 5:{
        _paper->citation_times = item->text().toInt();
        break;
    }
    case 6:{
        _paper->id = item->text().toStdString();
        break;
    }
    case 7:{
        _paper->abstract = item->text().toStdString();
        break;
    }
    default:
        break;
    }

    scisl::sci_sl_file* sl_file = scisl::sci_sl_file_visitor_adaptor::get_instance()->get_sl_file(_paper);
    sl_file->write((char*)sl_file->path());
}
