#include "mainframe.h"

using namespace std;

MainFrame::MainFrame()
{
    version = "1.0";

    setWindowTitle("OFLC V" + version);

    QWidget *zoneCentrale = new QWidget;

    resize(500, 500);

         QMenu *menuFile = menuBar()->addMenu("&Fichier");
         QMenu *menuAbout = menuBar()->addMenu("&Autres");

         QAction *actionNew = menuFile->addAction("&Nouveau");
         QAction *actionAbout = menuAbout->addAction("&À propos");


         connect(actionNew, SIGNAL(triggered()), this, SLOT(New()));
         connect(actionAbout, SIGNAL(triggered()), this, SLOT(About()));

    setCentralWidget(zoneCentrale);

    MainFrame::New();
}

void MainFrame::New()
{
    GB_Main_Title_0 = new QLabel;
    GB_Main_Title_0->setText("");
    GB_Main_Title_0->setAlignment(Qt::AlignCenter);

    GB_Main_Title_1 = new QLabel;
    GB_Main_Title_1->setText("Formule de calcul de l'atténuation sur le lien optique");
    GB_Main_Title_1->setAlignment(Qt::AlignCenter);

    GB_Main_Title_2 = new QLabel;
    GB_Main_Title_2->setText("AT = n x C + c x J + L x a + M");
    GB_Main_Title_2->setAlignment(Qt::AlignCenter);

    GB_Main_Title_3 = new QLabel;
    GB_Main_Title_3->setText("________________________________");
    GB_Main_Title_3->setAlignment(Qt::AlignCenter);

    GB_Main_Title_4 = new QLabel;
    GB_Main_Title_4->setText("n : nombre de connecteurs");
    GB_Main_Title_4->setAlignment(Qt::AlignCenter);

    GB_Main_Title_5 = new QLabel;
    GB_Main_Title_5->setText("C : atténuation pour un connecteur optique (dB)");
    GB_Main_Title_5->setAlignment(Qt::AlignCenter);

    GB_Main_Title_6 = new QLabel;
    GB_Main_Title_6->setText("c : nombre d'épissures dans la section élémentaire de câble");
    GB_Main_Title_6->setAlignment(Qt::AlignCenter);

    GB_Main_Title_7 = new QLabel;
    GB_Main_Title_7->setText("J : atténuation pour une épissure (dB)");
    GB_Main_Title_7->setAlignment(Qt::AlignCenter);

    GB_Main_Title_8 = new QLabel;
    GB_Main_Title_8->setText("M : marge de système (les cordons de raccordement, courbures de câble, événements imprévisibles d'atténuation optique, et ainsi de suite, devraient être considérés autour de 3dB)");
    GB_Main_Title_8->setAlignment(Qt::AlignCenter);

    GB_Main_Title_9 = new QLabel;
    GB_Main_Title_9->setText("a : atténuation pour le câble optique (dB/km)");
    GB_Main_Title_9->setAlignment(Qt::AlignCenter);

    GB_Main_Title_10 = new QLabel;
    GB_Main_Title_10->setText("L : longueur totale du câble optique");
    GB_Main_Title_10->setAlignment(Qt::AlignCenter);

    GB_Main_n_Line = new QDoubleSpinBox;
    GB_Main_C_Line = new QDoubleSpinBox;
    GB_Main_C_Line->setSuffix(" dB");
    GB_Main_c_Line = new QDoubleSpinBox;
    GB_Main_J_Line = new QDoubleSpinBox;
    GB_Main_J_Line->setSuffix(" dB");
    GB_Main_M_Line = new QDoubleSpinBox;
    GB_Main_a_Line = new QDoubleSpinBox;
    GB_Main_a_Line->setSuffix(" dB/km");
    GB_Main_L_Line = new QDoubleSpinBox;

    QFormLayout *titles = new QFormLayout;
    titles->addWidget(GB_Main_Title_0);
    titles->addWidget(GB_Main_Title_1);
    titles->addWidget(GB_Main_Title_2);
    titles->addWidget(GB_Main_Title_3);
    titles->addWidget(GB_Main_Title_4);
    titles->addWidget(GB_Main_Title_5);
    titles->addWidget(GB_Main_Title_6);
    titles->addWidget(GB_Main_Title_7);
    titles->addWidget(GB_Main_Title_8);
    titles->addWidget(GB_Main_Title_9);
    titles->addWidget(GB_Main_Title_10);

    calc = new QPushButton("&Calculer");



    QFormLayout *mainLayout = new QFormLayout;
    mainLayout->addRow("&n :", GB_Main_n_Line);
    mainLayout->addRow("&C :", GB_Main_C_Line);
    mainLayout->addRow("&c :", GB_Main_c_Line);
    mainLayout->addRow("&J :", GB_Main_J_Line);
    mainLayout->addRow("&M :", GB_Main_M_Line);
    mainLayout->addRow("&a :", GB_Main_a_Line);
    mainLayout->addRow("&L :", GB_Main_L_Line);
    mainLayout->addWidget(calc);

    QGroupBox *GB_Titles = new QGroupBox();
    GB_Titles->setLayout(titles);

    QGroupBox *GB_Main = new QGroupBox();
    GB_Main->setLayout(mainLayout);

    QVBoxLayout *layoutMainL = new QVBoxLayout;
    layoutMainL->addWidget(GB_Titles);
    layoutMainL->addWidget(GB_Main);

    QWidget *layout = new QWidget();
    layout->setLayout(layoutMainL);

    connect(calc, SIGNAL(clicked()), this, SLOT(Calc()));

    setCentralWidget(layout);
}

void MainFrame::Calc()
{

    double resultat(0);

    resultat= GB_Main_n_Line->value() * GB_Main_C_Line->value() + GB_Main_c_Line->value() * GB_Main_J_Line->value() + GB_Main_L_Line->value() * GB_Main_a_Line->value() + GB_Main_M_Line->value();

    string resultats = to_string(resultat);
    QMessageBox::information(this, "Calcul", QString("AT= ") + QString::fromStdString(resultats) + QString(" dB"));
}

void MainFrame::About()
{
    QMessageBox::information(this, tr("A propos..."), tr("OFLC (Optical Fiber Loss Calculator) est un Logiciel créé par Exiel en 2020."));
}
