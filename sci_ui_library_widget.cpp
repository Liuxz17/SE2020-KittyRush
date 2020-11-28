#include "sci_ui_library_widget.h"
#include "ui_sci_ui_library_widget.h"

#include <QDebug>
#include <QMouseEvent>

sci_ui_library_widget::sci_ui_library_widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sci_ui_library_widget)
{
    ui->setupUi(this);


    //treeView_library_file_tree = new QTreeView(ui->centralwidget);
    //treeView_library_file_tree->setObjectName(QString::fromUtf8("treeView_library_file_tree"));
    //treeView_library_file_tree->setGeometry(QRect(0, 0, 256, 192));

    //设置右键自定义菜单
    this->ui->treeView_library_file_tree->setContextMenuPolicy(Qt::CustomContextMenu);

    model = new QStandardItemModel(ui->treeView_library_file_tree);//创建模型
    ui->treeView_library_file_tree->setModel(model);

    QStandardItem * item = new QStandardItem(tr("example"));//创建一个条目对象

    sci_ui_folder *object = new sci_ui_folder(item);
    QVariant variant;
    variant.setValue(object);

    item->setData(variant);
    //qDebug()<<item->data(Qt::DisplayRole);

    model->appendRow(item);//通过模型对象添加这个条目
}

sci_ui_library_widget::~sci_ui_library_widget()
{
    delete ui;
}

void sci_ui_library_widget::on_treeView_library_file_tree_doubleClicked(const QModelIndex &index)
{
    sci_ui_file* file = index.data(Qt::UserRole+1).value<sci_ui_file*>();
    QWidget* edit_widget = file->edit_widget(this);

    this->ui->tabWidget_file_edit->addTab(edit_widget,index.data().toString());
    //ui->tabWidget_->addTab(tabCalibration, QIcon("Resources\\a10.ico"), tr("校准"));//在后面添加带图标的选项卡
    //右边窗口显示详细信息
}

void sci_ui_library_widget::on_treeView_library_file_tree_clicked(const QModelIndex &index)
{
    qDebug()<<"library file tree right clicked";
    qDebug()<<ui->treeView_library_file_tree->currentIndex();
    if(qApp->mouseButtons() == Qt::RightButton){
        //右键点击
        this->hide();
    }

}

void sci_ui_library_widget::mousePressEvent(QMouseEvent *event){
    //获取点击的下标
    qDebug() << event->x() << ":" << event->y();
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "左键" ;
    }
    else if(event->button() == Qt::RightButton)
    {
        qDebug() << "右键" ;
    }
}



void sci_ui_library_widget::on_treeView_library_file_tree_customContextMenuRequested(const QPoint &pos)
{
    QModelIndex index=ui->treeView_library_file_tree->currentIndex();
    sci_ui_file* file = index.data(Qt::UserRole+1).value<sci_ui_file*>();

    QMenu* menu=file->context_menu(this);
    menu->exec(QCursor::pos()); //在鼠标点击的位置显示鼠标右键菜单
}
