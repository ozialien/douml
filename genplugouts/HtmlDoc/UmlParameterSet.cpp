
#include "UmlActivityPin.h"
#include "UmlParameterSet.h"
//Added by qt3to4:
#include <QByteArray>

QByteArray UmlParameterSet::sKind()
{
    return "parameter set";
}

void UmlParameterSet::html(QByteArray, unsigned int, unsigned int)
{
    fw.write("<table><tr><td><div class=\"element\">Parameter set  <b>");
    writeq(name());
    fw.write("</b></div></td></tr></table>");

    QByteArray s = description();

    if (!s.isEmpty()) {
        fw.write("<p>");
        writeq(s);
        fw.write("<br /></p>");
    }

    fw.write("<p>Contains :");

    const QVector<UmlActivityPin*> & p = pins();
    unsigned n = p.size();

    for (unsigned i = 0; i != n; i += 1) {
        fw.write(" ");
        p[i]->write();
    }

    fw.write("</p>");

    write_properties();

    unload(FALSE, FALSE);

}

