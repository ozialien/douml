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

#ifndef TRANSITIONCANVAS_H
#define TRANSITIONCANVAS_H

#include "ArrowCanvas.h"
//Added by qt3to4:
#include <QTextStream>

class BrowserNode;
class TransitionData;
class DiagramItem;
class StereotypePropertiesCanvas;

class TransitionCanvas : public ArrowCanvas
{
    Q_OBJECT

protected:
    BrowserNode * br_begin;
    TransitionData * data;
    StereotypePropertiesCanvas * stereotypeproperties; // in the first segment
    DrawingLanguage drawing_language;
    Uml3States write_horizontally;
    Uml3States show_definition;

public:
    TransitionCanvas(UmlCanvas * canvas, DiagramItem * b,
                     DiagramItem * e, BrowserNode * bb,
                     int id, float d_start, float d_end,
                     TransitionData * d = 0);
    virtual ~TransitionCanvas();

    virtual void delete_it() override;
    virtual void delete_available(BooL & in_model, BooL & out_model) const override;
    virtual void remove(bool from_model) override;
    virtual void unconnect() override;

    virtual ArrowPointCanvas * brk(const QPoint &) override;
    virtual ArrowCanvas * join(ArrowCanvas * other, ArrowPointCanvas * ap) override;

    virtual void default_label_position() const override;
    void stereotype_default_position() const;

    virtual void save(QTextStream & st, bool ref, QString & warning) const override;

    virtual void history_load(QBuffer &) override;
    virtual void history_hide() override;

    virtual bool has_drawing_settings() const override;
    virtual void edit_drawing_settings(QList<DiagramItem *> &) override;
    virtual void clone_drawing_settings(const DiagramItem *src) override;

    virtual void apply_shortcut(const QString & s) override;
    void edit_drawing_settings();

    static TransitionCanvas * read(char *& st, UmlCanvas * canvas, char *);
    virtual BasicData * get_data() const override;

    virtual void open() override;
    virtual void menu(const QPoint &) override;

    virtual void setVisible(bool yes) override;
    virtual void moveBy(double dx, double dy) override;
    virtual void select_associated() override;
    virtual void check_stereotypeproperties() override;

    static void drop(BrowserNode *, UmlCanvas *);

    virtual bool represents(BrowserNode *) override;

protected:
    BrowserNode * update_begin(DiagramItem * cnend);
    using DiagramItem::update;
    void update(bool updatepos);
    void propagate_drawing_settings();

private slots:
    void modified();	// canvas must be updated
    void deleted();	// the relation is deleted
};

#endif
