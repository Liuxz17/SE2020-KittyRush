#include "sci_ui_library_widget.h"
#include "ui_sci_ui_library_widget.h"

#include <QDebug>
#include <QMouseEvent>

#include "sci_folder.h"
#include "sci_file_visitor_adaptor.h"

namespace scigui {

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

    model = new sci_file_model(this);//创建模型
    model->set_root(new scicore::sci_folder("root"));



    scicore::sci_folder* example = new scicore::sci_folder("example");
    model->add_file(example,model->get_root());

    scicore::sci_folder* example2 = new scicore::sci_folder("example2");
    model->add_file(example2,model->get_root());

    scicore::sci_folder* subfile = new scicore::sci_folder("subfile");
    model->add_file(subfile,example);

    scicore::sci_folder* subfile2 = new scicore::sci_folder("subfile2");
    model->add_file(subfile2,example2);

    ui->treeView_library_file_tree->setModel(model);

}

sci_ui_library_widget::~sci_ui_library_widget()
{
    delete ui;
}

void sci_ui_library_widget::on_treeView_library_file_tree_doubleClicked(const QModelIndex &index)
{

    //获取选取文件的指针
    scicore::sci_file* file = model->file_from_index(index);
    scigui::sci_ui_file* ui_file = scigui::ui_of_file(file, model);
    //右边打开编辑窗口，这里是随便加的
    QWidget* edit_widget = ui_file->edit_widget(this);
    this->ui->tabWidget_file_edit->addTab(edit_widget,index.data().toString());
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
    scicore::sci_file* file = this->model->file_from_index(index);

    scigui::sci_ui_file* ui_file = scigui::ui_of_file(file, model);
    QMenu* menu=ui_file->context_menu(this);
    menu->exec(QCursor::pos()); //在鼠标点击的位置显示鼠标右键菜单
}


}
