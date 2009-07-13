#include <QApplication>
#include <QDebug>
#include <QFrame>
#include <QHBoxLayout>
#include <marble/MarbleNavigator.h>
#include <marble/MarbleWidget.h>
 
using namespace Marble;
 
int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    QWidget *mainWindow = new QWidget();
    QHBoxLayout *hbox = new QHBoxLayout();

    MarbleNavigator *navigator = new MarbleNavigator(mainWindow);
    MarbleWidget *mapWidget = new MarbleWidget(mainWindow);
 
    mapWidget->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
    mapWidget->setDownloadUrl("http://tiles.openstreetmap.com");

    //Connect signals
    QObject::connect( navigator, SIGNAL( goHome() ), mapWidget, SLOT( goHome() ) );
    QObject::connect( navigator, SIGNAL( zoomIn() ), mapWidget, SLOT( zoomIn() ) );
    QObject::connect( navigator, SIGNAL( zoomOut() ), mapWidget, SLOT( zoomOut() ) );
    QObject::connect( navigator, SIGNAL( zoomChanged( int ) ), mapWidget, SLOT( zoomView( int ) ) );
    QObject::connect( navigator, SIGNAL( moveLeft() ), mapWidget, SLOT( moveLeft() ) );
    QObject::connect( navigator, SIGNAL( moveRight() ), mapWidget, SLOT( moveRight() ) );
    QObject::connect( navigator, SIGNAL( moveUp() ), mapWidget, SLOT( moveUp() ) );
    QObject::connect( navigator, SIGNAL( moveDown() ), mapWidget, SLOT( moveDown() ) );
    QObject::connect( mapWidget, SIGNAL( zoomChanged( int ) ), navigator, SLOT( changeZoom( int ) ) );

    hbox->addWidget( navigator );
    hbox->addWidget( mapWidget );
    mainWindow->setLayout( hbox );
    mainWindow->show();

    //Drawing test bit
    /*
    mapWidget->setShowOverviewMap ( false );
    mapWidget->setShowScaleBar ( false );
    mapWidget->setShowCompass ( false );
    mapWidget->setShowClouds ( false );
    mapWidget->setShowAtmosphere ( false );
    mapWidget->setShowCrosshairs ( true );
    mapWidget->setShowGrid ( false );
    mapWidget->setShowPlaces ( true );
    mapWidget->setShowCities ( true );
    mapWidget->setShowTerrain ( true );
    mapWidget->setShowOtherPlaces ( true );
    mapWidget->setShowRelief ( false );
    mapWidget->setShowElevationModel ( false );
    mapWidget->setShowIceLayer ( false );
    mapWidget->setShowBorders ( true );
    mapWidget->setShowRivers ( true );
    mapWidget->setShowLakes ( true );
    mapWidget->setShowGps ( true );
    mapWidget->setShowFrameRate ( false );
    */

    mapWidget->setCenterLongitude( -0.2 );
    mapWidget->setCenterLatitude( 51.585 );

 
    return app.exec();
}