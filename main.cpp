#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <qml_init.hpp>
#include <orm_pqxx.hpp>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    DataBaseAccess::Instanse(
        "user=postgres "
        "host=127.0.0.1 "
        "port=5432 "
        "password=9000 "
        "dbname=task_app"
    );
        
    QmlSingletonModels::Instanse();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/MainWindow.qml")));

    return app.exec();
}
