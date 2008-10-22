/* Copyright (C) 2007 - 2008 Jan Kundrát <jkt@gentoo.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Steet, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "Imap/MailboxModel.h"
#include "Imap/MailboxTree.h"

namespace Imap {
namespace Mailbox {

MailboxModel::MailboxModel( QObject* parent, Model* model ): QSortFilterProxyModel(parent)
{
    setSourceModel( model );
    setDynamicSortFilter( true );
}

bool MailboxModel::filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const
{
    return dynamic_cast<TreeItemMailbox*>(
            static_cast<TreeItem*>(
                sourceModel()->index( source_row, 0, source_parent ).internalPointer()
                ) );
}

}
}

#include "MailboxModel.moc"
