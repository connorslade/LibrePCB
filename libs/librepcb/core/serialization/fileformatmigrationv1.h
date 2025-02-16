/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * https://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBREPCB_CORE_FILEFORMATMIGRATIONV1_H
#define LIBREPCB_CORE_FILEFORMATMIGRATIONV1_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "fileformatmigration.h"

#include <QtCore>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

class SExpression;

/*******************************************************************************
 *  Class FileFormatMigrationV1
 ******************************************************************************/

/**
 * @brief Migration to upgrade file format v1.0
 */
class FileFormatMigrationV1 : public FileFormatMigration {
  Q_OBJECT

public:
  // Constructors / Destructor
  explicit FileFormatMigrationV1(QObject* parent = nullptr) noexcept;
  FileFormatMigrationV1(const FileFormatMigrationV1& other) = delete;
  virtual ~FileFormatMigrationV1() noexcept;

  // General Methods
  virtual void upgradeComponentCategory(TransactionalDirectory& dir) override;
  virtual void upgradePackageCategory(TransactionalDirectory& dir) override;
  virtual void upgradeSymbol(TransactionalDirectory& dir) override;
  virtual void upgradePackage(TransactionalDirectory& dir) override;
  virtual void upgradeComponent(TransactionalDirectory& dir) override;
  virtual void upgradeDevice(TransactionalDirectory& dir) override;
  virtual void upgradeLibrary(TransactionalDirectory& dir) override;
  virtual void upgradeProject(TransactionalDirectory& dir,
                              QList<Message>& messages) override;
  virtual void upgradeWorkspaceData(TransactionalDirectory& dir) override;

  // Operator Overloadings
  FileFormatMigrationV1& operator=(const FileFormatMigrationV1& rhs) = delete;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace librepcb

#endif
