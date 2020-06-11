#include "CRankDlg.h"
#include "ui_CRankDlg.h"


//调整堆
void HeapAdjust (RankInformation RInfo[], int length, int k)
{
    RankInformation tmp = RInfo[k];
    int i=2*k+1;
    while (i<length) {
        if (i+1<length && RInfo[i].nScore>RInfo[i+1].nScore) //选取最小的结点位置
            ++i;
        if (tmp.nScore < RInfo[i].nScore) //不用交换
            break;
        RInfo[k] = RInfo[i]; //交换值
        k = i; //继续查找
        i = 2*k+1;
    }
    RInfo[k] = tmp;
}

//堆排序
void HeapSort (RankInformation RInfo[], int length)
{
    if (RInfo == NULL || length <= 0)
        return;
    for (int i=length/2-1; i>=0; --i) {
        HeapAdjust(RInfo, length, i); //从第二层开始建堆
    }
    for (int i=length-1; i>=0; --i) {
        std::swap(RInfo[0], RInfo[i]);
        HeapAdjust(RInfo, i, 0); //从顶点开始建堆, 忽略最后一个
    }
    return;
}

CRankDlg::CRankDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRankDlg)
{
    ui->setupUi(this);
    QStandardItemModel  *model = new QStandardItemModel();
       model->setColumnCount(4);//设置各列名称
       model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("name"));
       model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("time"));
       model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("score"));
       model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("rank"));
       ui->tableView->setModel(model);
       //表头信息显示居左
       ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);


       ofstream write;
       ifstream read;
       RankInformation *RInfo=new RankInformation[20];
       int peopleCount=0,InfoSize=20;
       string temp;

       read.open("result.txt", ios::in);//从文件读取全部数据
       getline(read,temp);
       while (!read.eof()) {
           string name;
           int time,score;

           istringstream is(temp);
           is>>name>>time>>score;
           if(peopleCount==InfoSize){//内存不足时动态分配内存
               RankInformation *temp=new RankInformation[++InfoSize];
               memcpy(temp,RInfo,(InfoSize-1)*sizeof(RankInformation));
               delete[] RInfo;
               RInfo=temp;
           }
           RInfo[peopleCount].strName=QString::fromStdString(name);
           RInfo[peopleCount].nTime=time;
           RInfo[peopleCount].nScore=score;
           //cout<<RInfo[peopleCount].nScore<<peopleCount<<endl;
           peopleCount++;
           getline(read,temp);//再读一行
       }

       HeapSort(RInfo,peopleCount);
       int setCount;
       if(peopleCount<10){
           setCount=peopleCount;
       }else{
           setCount=10;
       }
       for (int i=0; i<setCount; i++) {
           model->setItem(i,0,new QStandardItem(RInfo[i].strName));
            //设置字符颜色
           model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
            //设置字符位置
           model->item(i,0)->setTextAlignment(Qt::AlignCenter);

           model->setItem(i,1,new QStandardItem(QString::number(RInfo[i].nTime)));
           model->item(i,1)->setForeground(QBrush(QColor(255, 0, 0)));
           model->item(i,1)->setTextAlignment(Qt::AlignCenter);

           model->setItem(i,2,new QStandardItem(QString::number(RInfo[i].nScore)));
           model->item(i,2)->setForeground(QBrush(QColor(255, 0, 0)));
           model->item(i,2)->setTextAlignment(Qt::AlignCenter);

           model->setItem(i,3,new QStandardItem(QString::number(i+1)));
           model->item(i,3)->setForeground(QBrush(QColor(255, 0, 0)));
           model->item(i,3)->setTextAlignment(Qt::AlignCenter);
       }
}

CRankDlg::~CRankDlg()
{
    delete ui;
}
