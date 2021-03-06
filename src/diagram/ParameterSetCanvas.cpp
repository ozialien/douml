// *************************************************************************
//
// Copyright 2004-2010 Bruno PAGES  .
// Copyright 2012-2013 Nikolai Marchenko.
// Copyright 2012-2013 Leonardo Guilherme.
//
// This file is part of the DOUML Uml Toolkit.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License Version 3.0 as published by
// the Free Software Foundation and appearing in the file LICENSE.GPL included in the
//  packaging of this file.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License Version 3.0 for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// e-mail : doumleditor@gmail.com
// home   : http://sourceforge.net/projects/douml
//
// *************************************************************************





#include <math.h>

#include <qpainter.h>
//#include <q3popupmenu.h>
#include <qcursor.h>
//Added by qt3to4:
#include <QTextStream>
#include <QList>

#include "ParameterSetCanvas.h"
#include "BrowserParameterSet.h"
#include "ParameterSetData.h"
#include "ParameterSetCanvas.h"
#include "ActivityActionCanvas.h"
#include "PinCanvas.h"
#include "UmlCanvas.h"
#include "BrowserDiagram.h"
#include "UmlGlobal.h"
#include "SettingsDialog.h"
#include "myio.h"
#include "ToolCom.h"
#include "Tool.h"
#include "ui/menufactory.h"
#include "Settings.h"
#include "strutil.h"
#include "translate.h"

ParameterSetCanvas::ParameterSetCanvas(BrowserNode * bn, UmlCanvas * canvas,
                                       int id, ActivityActionCanvas * a)
    : DiagramCanvas(0, canvas, 0, 0, 2, 2, id), act(a)
{
    browser_node = bn;
    itscolor = UmlDefaultColor;

    if (id == 0) {
        // not on read
        update();
        setZValue(a->zValue());  // note : pins have z+2 to be upper the parameter sets with their lines
        check_stereotypeproperties();
    }

    connect(bn->get_data(), SIGNAL(changed()), this, SLOT(modified()));
    connect(bn->get_data(), SIGNAL(deleted()), this, SLOT(deleted()));
    connect(DrawingSettings::instance(), SIGNAL(changed()), this, SLOT(modified()));
}

ParameterSetCanvas::~ParameterSetCanvas()
{
}

void ParameterSetCanvas::delete_it()
{
    disconnect(browser_node->get_data(), 0, this, 0);
    disconnect(DrawingSettings::instance(), SIGNAL(changed()), this, SLOT(modified()));
    disconnect_pins();

    DiagramCanvas::delete_it();
}

void ParameterSetCanvas::deleted()
{
    delete_it();
    act->deleted(this);
    canvas()->update();
}

void ParameterSetCanvas::remove(bool from_model)
{
    if (! from_model)
        delete_it();
    else
        browser_node->delete_it();	// will remove canvas
}

void ParameterSetCanvas::disconnect_pins()
{
    QList<PinCanvas *>::Iterator iter;

    iter = params.begin();

    while (! params.isEmpty()) {
        disconnect((*iter)->get_bn()->get_data(), SIGNAL(deleted()), this, SLOT(pin_deleted()));
        iter = params.erase(iter);
    }
}

void ParameterSetCanvas::delete_available(BooL & in_model, BooL & out_model) const
{
    out_model |= TRUE;
    in_model |= browser_node->is_writable();
}

void ParameterSetCanvas::update()
{
    used_color = (itscolor == UmlDefaultColor)
            ? the_canvas()->browser_diagram()->get_color(UmlActivityPin)
            : itscolor;

    disconnect_pins();

    QList<PinCanvas *> pincanvas = act->get_pins();
    QList<PinCanvas *>::ConstIterator iter;
    QList<BrowserPin *> pins = ((ParameterSetData *) browser_node->get_data())->get_pins();

    for (iter = pincanvas.begin(); iter != pincanvas.end(); ++iter) {
        if (pins.indexOf((BrowserPin *)(*iter)->get_bn()) != -1) {
            params.append(*iter);
            connect((*iter)->get_bn()->get_data(), SIGNAL(deleted()), this, SLOT(pin_deleted()));
        }
    }

    check_position();
}

void ParameterSetCanvas::pin_deleted()
{
    QList<PinCanvas *>::Iterator iter = params.begin();

    while (iter != params.end()) {
        if (!(*iter)->visible()) {
            disconnect((*iter)->get_bn()->get_data(), SIGNAL(deleted()), this, SLOT(pin_deleted()));
            iter = params.erase(iter);
        }
        else
            ++iter;
    }

    check_position();
}

void ParameterSetCanvas::check_position()
{
    if (params.isEmpty()) {
        // hide it but still visible
        QGraphicsRectItem::moveBy(-1 - x(), -1 - y());
        QGraphicsRectItem::setRect(0,0,0, 0);
    }
    else {
        int x_min = the_canvas()->width();
        int x_max = 0;
        int y_min = the_canvas()->height();
        int y_max = 0;

        QList<PinCanvas *>::Iterator iter;

        for (iter = params.begin(); iter != params.end(); ++iter) {
            int i;

            i = (int)(*iter)->x();

            if (i < x_min)
                x_min = i;

            i = (*iter)->rect().right();

            if (i > x_max)
                x_max = i;

            i = (int)(*iter)->y();

            if (i < y_min)
                y_min = i;

            i = (*iter)->rect().bottom();

            if (i > y_max)
                y_max = i;
        }

        QRect r_act = act->rect();
        int margin = (the_canvas()->zoom() <= 0.9) ? 2 : 3;

        if (x_min < r_act.right())
            x_min -= margin;

        if (x_max > r_act.x())
            x_max += margin;

        if (y_min < r_act.bottom())
            y_min -= margin;

        if (y_max > r_act.y())
            y_max += margin;

        QGraphicsRectItem::moveBy(x_min - x(), y_min - y());
        QGraphicsRectItem::setRect(0,0,x_max - x_min + 1, y_max - y_min + 1);
    }
}

void ParameterSetCanvas::change_scale()
{
    // does nothing, made by do_change_scale called by
    // ActivityActionCanvas::change_scale()
}

void ParameterSetCanvas::do_change_scale()
{
    // action and pins already in position, can check
    check_position();
}

void ParameterSetCanvas::moveBy(double, double)
{
    // does nothing : can't be moved by hand
    // else do_moveBy called by ActivityActionCanvas::moveBy()
}

void ParameterSetCanvas::do_moveBy(double, double)
{
    // action and pins already in position, can check
    check_position();
}

bool ParameterSetCanvas::primaryItem() const
{
    return FALSE;
}

void ParameterSetCanvas::draw(QPainter & p)
{
    if (! visible()) return;

    p.setRenderHint(QPainter::Antialiasing, true);
    QBrush brsh = p.brush();
    QColor bckgrnd = p.background().color();
    QBrush backBrush = p.background();

    p.setBackgroundMode((used_color == UmlTransparent)
                        ? ::Qt::TransparentMode
                        : ::Qt::OpaqueMode);

    QColor co = color(used_color);
    QRect r = rect();
    FILE * fp = svg();

    backBrush.setColor(co);
    p.setBackground(backBrush);

    if (used_color != UmlTransparent)
        p.setBrush(co);

    if (fp != 0)
        fprintf(fp, "<g>\n"
                    "\t<rect fill=\"%s\" stroke=\"black\" stroke-width=\"1\" stroke-opacity=\"1\""
                    " x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" />\n"
                    "</g>\n",
                svg_color(used_color),
                r.x(), r.y(), r.width() - 1, r.height() - 1);

    p.drawRect(r);

    backBrush.setColor(bckgrnd);
    p.setBackground(backBrush);
    p.setBrush(brsh);

    if (selected())
        show_mark(p, r);
}

void ParameterSetCanvas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    draw(*painter);
}

UmlCode ParameterSetCanvas::typeUmlCode() const
{
    return UmlParameterSet;
}

bool ParameterSetCanvas::copyable() const
{
    return act->selected();
}

void ParameterSetCanvas::open()
{
    browser_node->open(FALSE);
}

void ParameterSetCanvas::menu(const QPoint &)
{
    QMenu m(0);
    QMenu toolm(0);
    int index;

    MenuFactory::createTitle(m, browser_node->get_data()->definition(FALSE, TRUE));
    m.addSeparator();
    MenuFactory::addItem(m, tr("Upper"), 0);
    MenuFactory::addItem(m, tr("Lower"), 1);
    MenuFactory::addItem(m, tr("Go up"), 13);
    MenuFactory::addItem(m, tr("Go down"), 14);
    m.addSeparator();
    MenuFactory::addItem(m, tr("Edit drawing settings"), 2);
    m.addSeparator();
    MenuFactory::addItem(m, tr("Edit parameter set"), 3);
    m.addSeparator();
    MenuFactory::addItem(m, tr("Select in browser"), 4);

    if (linked())
        MenuFactory::addItem(m, tr("Select linked items"), 5);

    m.addSeparator();

    if (browser_node->is_writable()) {
        MenuFactory::addItem(m, tr("Delete from model"), 8);
        m.addSeparator();
    }

    if (Tool::menu_insert(&toolm, UmlParameterSet, 20))
        MenuFactory::insertItem(m, tr("Tool"), &toolm);

    QAction* retAction = m.exec(QCursor::pos());
    if(retAction)
    {
        switch (index = retAction->data().toInt()) {
        case 0:
            act->upper();
            modified();	// call package_modified()
            return;

        case 1:
            act->lower();
            modified();	// call package_modified()
            return;

        case 13:
            act->z_up();
            modified();	// call package_modified()
            return;

        case 14:
            act->z_down();
            modified();	// call package_modified()
            return;

        case 2:
            edit_drawing_settings();
            return;

        case 3:
            browser_node->open(TRUE);
            return;

        case 4:
            browser_node->select_in_browser();
            return;

        case 5:
            the_canvas()->unselect_all();
            select_associated();
            return;

        case 8:
            //delete from model
            browser_node->delete_it();	// will delete the canvas
            break;

        default:
            if (index >= 20)
                ToolCom::run(Tool::command(index - 20), browser_node);

            return;
        }
    }

    package_modified();
}

void ParameterSetCanvas::apply_shortcut(const QString & s)
{
    if (s == "Select in browser") {
        browser_node->select_in_browser();
        return;
    }
    else if (s == "Upper")
        act->upper();
    else if (s == "Lower")
        act->lower();
    else if (s == "Go up")
        act->z_up();
    else if (s == "Go down")
        act->z_down();
    else if (s == "Edit drawing settings") {
        edit_drawing_settings();
        return;
    }
    else {
        browser_node->apply_shortcut(s);
        return;
    }

    modified();
    package_modified();
}

void ParameterSetCanvas::edit_drawing_settings()
{
    for (;;) {
        ColorSpecVector co(1);

        co[0].set(tr("parameter set color"), &itscolor);

        SettingsDialog dialog(0, &co, FALSE);

        dialog.raise();

        if (dialog.exec() == QDialog::Accepted)
            modified();	// call package_modified()

        if (!dialog.redo())
            break;
    }
}

bool ParameterSetCanvas::has_drawing_settings() const
{
    return TRUE;
}

void ParameterSetCanvas::edit_drawing_settings(QList<DiagramItem *> & l)
{
    for (;;) {
        ColorSpecVector co(1);
        UmlColor itscolor;

        co[0].set(tr("parameter set color"), &itscolor);

        SettingsDialog dialog(0, &co, FALSE, TRUE);

        dialog.raise();

        if ((dialog.exec() == QDialog::Accepted) && !co[0].name.isEmpty()) {
            foreach (DiagramItem *item, l) {
                ParameterSetCanvas *canvas = (ParameterSetCanvas *)item;
                canvas->itscolor = itscolor;
                canvas->modified();	// call package_modified()
            }
        }

        if (!dialog.redo())
            break;
    }
}

void ParameterSetCanvas::clone_drawing_settings(const DiagramItem *src)
{
    const ParameterSetCanvas * x = (const ParameterSetCanvas *) src;
    itscolor = x->itscolor;
    modified();
}

QString ParameterSetCanvas::may_start(UmlCode &) const
{
    return tr("illegal");
}

QString ParameterSetCanvas::may_connect(UmlCode &, const DiagramItem *) const
{
    return tr("illegal");
}

void ParameterSetCanvas::modified()
{
    hide();
    update();
    show();
    check_stereotypeproperties();
    canvas()->update();
    package_modified();
}

void ParameterSetCanvas::connexion(UmlCode, DiagramItem *,
                                   const QPoint &, const QPoint &)
{
    // does nothing
}

void ParameterSetCanvas::save(QTextStream & st, bool ref, QString & warning) const
{
    if (ref) {
        st << "parametersetcanvas_ref " << get_ident() << " // "
           << browser_node->full_name();
    }
    else {
        nl_indent(st);
        st << "parametersetcanvas " << get_ident() << " ";
        browser_node->save(st, TRUE, warning);
        nl_indent(st);

        if (itscolor != UmlDefaultColor)
            st << "  color " << stringify(itscolor);

        save_xyz(st, this, "  xyz");
        save_stereotype_property(st, warning);
        nl_indent(st);
        st << "end";
    }
}

ParameterSetCanvas * ParameterSetCanvas::read(char *& st, UmlCanvas * canvas,
                                              char * k, ActivityActionCanvas * a)
{
    if (!strcmp(k, "parametersetcanvas_ref"))
        return ((ParameterSetCanvas *) dict_get(read_id(st), "parametersetcanvas", canvas));
    else if (!strcmp(k, "parametersetcanvas")) {
        int id = read_id(st);
        BrowserParameterSet * br = BrowserParameterSet::read_ref(st);
        ParameterSetCanvas * result = new ParameterSetCanvas(br, canvas, id, a);

        k = read_keyword(st);

        read_color(st, "color", result->itscolor, k);	// updates k

        if (!strcmp(k, "xyz"))
            read_xyz(st, result);
        else
            wrong_keyword(k, "xyz");

        // note : width_scale100 & height_scale100 useless, position depend on pins
        result->update();
        result->show();

        k = read_keyword(st);

        result->read_stereotype_property(st, k);	// updates k

        if (strcmp(k, "end"))
            wrong_keyword(k, "end");

        result->check_stereotypeproperties();

        return result;
    }
    else
        return 0;
}

void ParameterSetCanvas::history_hide()
{
    QGraphicsItem::setVisible(FALSE);
    disconnect(browser_node->get_data(), SIGNAL(changed()), this, SLOT(modified()));
    disconnect(browser_node->get_data(), SIGNAL(deleted()), this, SLOT(deleted()));
    disconnect(DrawingSettings::instance(), SIGNAL(changed()), this, SLOT(modified()));
    disconnect_pins();
}

void ParameterSetCanvas::history_save(QBuffer & b) const
{
    DiagramCanvas::history_save(b);
    // note :width_scale100 & height_scale100 useless, position depend on pins
    ::save(width(), b);
    ::save(height(), b);
}

void ParameterSetCanvas::history_load(QBuffer & b)
{
    DiagramCanvas::history_load(b);
    // note :width_scale100 & height_scale100 useless, position depend on pins

    int w, h;

    ::load(w, b);
    ::load(h, b);
    QGraphicsRectItem::setRect(rect().x(), rect().y(), w, h);

    connect(browser_node->get_data(), SIGNAL(changed()), this, SLOT(modified()));
    connect(browser_node->get_data(), SIGNAL(deleted()), this, SLOT(deleted()));
    connect(DrawingSettings::instance(), SIGNAL(changed()), this, SLOT(modified()));

    // note : pin list unchanged because history raz on item deletion
    QList<PinCanvas *>::Iterator iter;

    for (iter = params.begin(); iter != params.end(); ++iter)
        connect((*iter)->get_bn()->get_data(), SIGNAL(deleted()), this, SLOT(pin_deleted()));
}

