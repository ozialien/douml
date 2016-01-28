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

#ifndef ACTUALPARAMDATA_H
#define ACTUALPARAMDATA_H

#include <qobject.h>
//Added by qt3to4:
#include <QTextStream>

#include "AType.h"

class ToolCom;

class ActualParamData : public QObject
{
    Q_OBJECT

protected:
    BrowserClass * super;
    unsigned rank;
    AType value;

public:
    ActualParamData(BrowserClass * p, unsigned r);
    ActualParamData(const ActualParamData & p);
    BrowserClass * get_class() const {
        return super;
    };

    QString get_name(bool full = TRUE) const;

    const AType & get_value() const {
        return value;
    };
    void set_value(const AType & t);

    void send_uml_def(ToolCom * com);

    void save(QTextStream &, QString & warning) const;
    static ActualParamData * read(char *&);

protected slots:
    void on_delete();
};


#endif