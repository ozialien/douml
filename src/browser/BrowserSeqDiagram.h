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

#ifndef BROWSER_SEQDIAGRAM_H
#define BROWSER_SEQDIAGRAM_H

#include "BrowserDiagram.h"
#include "Settings.h"
//Added by qt3to4:
#include <QPixmap>
#include <QTextStream>
#include <QList>

class QPixmap;
class SeqDiagramWindow;
class SimpleData;

class BrowserSeqDiagram : public BrowserDiagram
{
    friend class StereotypesDialog;

protected:
    static QList<BrowserSeqDiagram *> imported;
    static QList<int> imported_ids;
    static QStringList its_default_stereotypes;
    static QStringList message_default_stereotypes;

    SimpleData * def;
    SeqDiagramWindow * window;
    SequenceDiagramSettings settings;
    SequenceDiagramSettings * used_settings;
    UmlColor note_color;
    UmlColor fragment_color;
    UmlColor duration_color;
    UmlColor continuation_color;
    UmlColor class_instance_color;
    bool overlapping_bars;

    BrowserSeqDiagram(BrowserSeqDiagram * model, BrowserNode * p);
    BrowserSeqDiagram(int id);
    void make();
    void exec_menu_choice(int rank);

public:
    BrowserSeqDiagram(const QString & s, BrowserNode * p, int id = 0);
    virtual ~BrowserSeqDiagram();

    virtual void delete_it() override;
    virtual BrowserNode * duplicate(BrowserNode * p,
                                    const QString & name = QString()) override;

    virtual const QPixmap * pixmap(int) const override;
    virtual void draw_svg() const override;

    virtual void menu() override;
    virtual void apply_shortcut(const QString & s) override;
    virtual void open(bool) override;
    virtual void on_close() override;
    virtual void read_session(char *& st) override;
    virtual UmlCode get_type() const override;
    virtual QString get_stype() const override;
    virtual int get_identifier() const override;
    virtual const char * help_topic() const override;
    virtual BasicData * get_data() const override;
    virtual void set_name(const QString & s) override;
    virtual void update_drawing_settings() override;
    virtual void get_sequencediagramsettings(SequenceDiagramSettings &) const override;
    void get_sequencediagramsettings_msg(SequenceDiagramSettings &) const;
    virtual UmlColor get_color(UmlCode) const override;
    virtual bool get_shadow() const override;
    virtual bool get_draw_all_relations() const override;
    virtual void dont_draw_all_relations() override;
    virtual bool get_auto_label_position() const override;
    virtual bool get_show_stereotype_properties() const override;
    virtual bool get_classinstwritehorizontally() const override;
    virtual ShowContextMode get_classinstshowmode() const override;
    virtual bool tool_cmd(ToolCom * com, const char * args) override;
    virtual void save(QTextStream &, bool ref, QString & warning) override;
    static BrowserSeqDiagram * read(char *& , char *, BrowserNode *);
    static BrowserNode * get_it(const char * k, int id);

    void edit_settings();
    bool is_overlapping_bars() const {
        return overlapping_bars;
    }
    void set_overlapping_bars(bool y) {
        overlapping_bars = y;
    }

    static BrowserSeqDiagram * add_sequence_diagram(BrowserNode * future_parent);

    static const QStringList & default_stereotypes();
    static const QStringList & msg_default_stereotypes();
    static void read_stereotypes(char *& , char *& k);
    static void save_stereotypes(QTextStream &);

    virtual void renumber(int phase) override;
    static void open_all();
    static void import();

    static void compute_referenced_by(QList<BrowserNode *> & l, BrowserNode *,
                                      const char * kc, char const * kr);
};

#endif
