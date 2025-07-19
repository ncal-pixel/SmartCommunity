#include "AddProperty.h"
#include "ui_AddProperty.h"
#include "database.h"
#include <QMessageBox>

AddProperty::AddProperty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProperty)
{
    ui->setupUi(this);
}
AddProperty::AddProperty(int id, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddProperty)
    , m_selectedId(id)
{
    ui->setupUi(this);

    ui->table->setColumnCount(12);
    ui->table->setHorizontalHeaderLabels({"ID", "姓名","房地产登记申请书", "身份证明材料", "不动产权属来源及证明文件", "不动产界址","空间界限","面积","与他人利害关系的说明材","商品房买卖合同","完税证明","维修基金收据"});
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table->setAlternatingRowColors(true);

    connect(ui->btnOK, &QPushButton::clicked, this, &AddProperty::onOK);
    connect(ui->btnCancle,&QPushButton::clicked,this,&AddProperty::onCancle);
    refreshTable();
    initComboBoxes();
}
AddProperty::~AddProperty()
{
    delete ui;
}

void AddProperty::refreshTable(){
    ui->table->setRowCount(0);
    auto& db=database::getInstance();
    qDebug()<<m_selectedId;
    QSqlQuery query=db.query("SELECT id, name, application_for_real_estate_registration, identity_proof_materials, documents_on_the_origin_and_proof_of_real_estate_ownership, materials_on_real_estate_boundaries, spatial_limits, area, explanatory_materials_on_stakeholder_relationships_with_others, commercial_housing_sales_contract, tax_payment_certificate, maintenance_fund_receipt FROM owner_property WHERE owner_id = ?",{m_selectedId});

    int row = 0;
    while (query.next()) {
        ui->table->insertRow(row);

        for (int col = 0; col < 12; col++) {
            QString val;
            if(col>1){
               val = (query.value(col).toString() == "1") ? "已上传电子版" : "未上传电子版";
            }else val = query.value(col).toString();
            QTableWidgetItem *item = new QTableWidgetItem(val);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->table->setItem(row, col, item);
        }

        row++;
    }
}

void AddProperty::initComboBoxes()
{

    ui->box1->clear();
    ui->box2->clear();
    ui->box3->clear();
    ui->box4->clear();
    ui->box5->clear();
    ui->box6->clear();
    ui->box7->clear();
    ui->box8->clear();
    ui->box9->clear();
    ui->box10->clear();
    ui->box11->clear();
    ui->box12->clear();

    ui->box1->addItem("***");
    ui->box2->addItem("***");
    ui->box3->addItem("请选择状态");
    ui->box4->addItem("请选择状态");
    ui->box5->addItem("请选择状态");
    ui->box6->addItem("请选择状态");
    ui->box7->addItem("请选择状态");
    ui->box8->addItem("请选择状态");
    ui->box9->addItem("请选择状态");
    ui->box10->addItem("请选择状态");
    ui->box11->addItem("请选择状态");
    ui->box12->addItem("请选择状态");

    constexpr int BOX_COUNT = 12;
    QComboBox* boxes[BOX_COUNT] = {
        ui->box1, ui->box2, ui->box3, ui->box4,
        ui->box5, ui->box6, ui->box7, ui->box8,
        ui->box9, ui->box10, ui->box11, ui->box12
    };
    for (int i = 2; i < BOX_COUNT; ++i) {
        boxes[i]->addItem("未上传电子版");
        boxes[i]->addItem("已上传电子版");
    }
}

void AddProperty::onOK(){
     int currentRow = ui->table->currentRow();
    int id = ui->table->item(currentRow, 0)->text().toInt();
    QComboBox* boxes[12] = {
        ui->box1, ui->box2, ui->box3, ui->box4,
        ui->box5, ui->box6, ui->box7, ui->box8,
        ui->box9, ui->box10, ui->box11, ui->box12
    };
    QString values[12];
    for (int i = 0; i < 12; ++i) {
        values[i] = boxes[i]->currentText();
    }
    QString a1,a2;
    int a[10]; // 存储转换后的数值状态
    for (int i = 2; i < 12; ++i) {
//         a1    = boxes[1]->currentText();
//           a2    = boxes[2]->currentText();
        if (values[i] == "已上传电子版") {
            a[i-2] = 1;
        } else{
            a[i-2] = 0;
        }
    }
    QString sql = "UPDATE owner_property SET "
                  "application_for_real_estate_registration = ?, "  // 修正拼写
                  "identity_proof_materials = ?, "
                  "documents_on_the_origin_and_proof_of_real_estate_ownership = ?, "
                  "materials_on_real_estate_boundaries = ?, "
                  "spatial_limits = ?, "
                  "area = ?, "
                  "explanatory_materials_on_stakeholder_relationships_with_others = ?, "
                  "commercial_housing_sales_contract = ?, "
                 "tax_payment_certificate = ?, maintenance_fund_receipt = ? "
                  "WHERE id = ? AND owner_id = ?";
    auto& db=database::getInstance();
    QSqlQuery query=db.query(sql,{a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],id,m_selectedId});
    refreshTable();
}

void AddProperty::onCancle(){
    close();
}
