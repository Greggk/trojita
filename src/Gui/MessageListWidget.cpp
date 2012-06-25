/* Copyright (C) 2006 - 2012 Jan Kundrát <jkt@flaska.net>

   This file is part of the Trojita Qt IMAP e-mail client,
   http://trojita.flaska.net/

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or the version 3 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "MessageListWidget.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include "MsgListView.h"

#include <QDebug>

namespace Gui {

MessageListWidget::MessageListWidget(QWidget *parent) :
    QWidget(parent), m_supportsFuzzySearch(false)
{
    tree = new MsgListView(this);

    m_quickSearchText = new QLineEdit(this);
    m_quickSearchText->setPlaceholderText(tr("Quick Search..."));
    m_quickSearchText->setEnabled(false);

    connect(m_quickSearchText, SIGNAL(returnPressed()), this, SLOT(slotApplySearch()));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_quickSearchText);
    layout->addWidget(tree);

}

void MessageListWidget::slotApplySearch()
{
    emit requestingSearch(searchConditions());
}

void MessageListWidget::slotAutoEnableDisableSearch()
{
    if (tree && tree->model()) {
        m_quickSearchText->setEnabled(tree->model()->rowCount());
    } else {
        m_quickSearchText->setEnabled(false);
    }
}

QStringList MessageListWidget::searchConditions() const
{
    if (!m_quickSearchText->isEnabled() || m_quickSearchText->text().isEmpty())
        return QStringList();

    return QStringList() << QLatin1String(m_supportsFuzzySearch ? "FUZZY SUBJECT" : "SUBJECT") << m_quickSearchText->text();
}

void MessageListWidget::setFuzzySearchSupported(bool supported)
{
    m_supportsFuzzySearch = supported;
}

void MessageListWidget::clearSearch()
{
    m_quickSearchText->clear();
    slotApplySearch();
}

}
