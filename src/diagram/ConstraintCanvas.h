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

#ifndef CONSTRAINTCANVAS_H
#define CONSTRAINTCANVAS_H

#include "NoteCanvas.h"
#include "BrowserNode.h"
//Added by qt3to4:
#include <QTextStream>
#include <QList>

class CdClassCanvas;

class ConstraintCanvas : public NoteCanvas
{
    Q_OBJECT

    friend class ConstraintDialog;
    friend class ConstraintTable;

protected:
    bool indicate_visible;
    CdClassCanvas * cl;
    QList<BrowserNode *> hidden_visible;
    QList<BasicData *> connect_list;	// class only
    BrowserNodeList elements;

public:
    ConstraintCanvas(UmlCanvas * canvas, CdClassCanvas *, int x, int y, int id);
    ConstraintCanvas(UmlCanvas * canvas, CdClassCanvas *, QString);
    virtual ~ConstraintCanvas();

    virtual void delete_it() override;

    virtual UmlCode typeUmlCode() const override;
    virtual void delete_available(BooL & in_model, BooL & out_model) const override;
    virtual bool copyable() const override;
    virtual void history_load(QBuffer &) override;
    virtual void history_hide() override;
    virtual void open() override;
    virtual void menu(const QPoint &) override;

    virtual void apply_shortcut(const QString & s) override;
    virtual bool has_drawing_settings() const override;
    virtual void edit_drawing_settings(QList<DiagramItem *> &) override;
    virtual void clone_drawing_settings(const DiagramItem *src) override;

    virtual void save(QTextStream  & st, bool ref, QString & warning) const override;
    static ConstraintCanvas * read(char *& , UmlCanvas *, char *, CdClassCanvas *);

    static ConstraintCanvas * compute(UmlCanvas * canvas,
                                      CdClassCanvas * cl,
                                      ConstraintCanvas * current);

public slots:
    virtual void update() override;
};

#endif
