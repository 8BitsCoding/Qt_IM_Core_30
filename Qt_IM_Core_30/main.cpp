#include <QtCore/QCoreApplication>

#include <qdebug.h>

QByteArray makeData() {
	QByteArray data;

	for (int i = 0; i < 1000; i++) {
		data.append(QString::number(i) + "\r\n");
	}

	return data;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QByteArray data = makeData();
	QByteArray compressed = qCompress(data);
	QByteArray decompressed = qUncompress(compressed);

	qInfo() << "Original: " << data.length();
	qInfo() << "Compressed: " << compressed.length();
	qInfo() << "Decompressed: " << decompressed.length();

	return a.exec();
}
