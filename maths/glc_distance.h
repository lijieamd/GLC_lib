/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005-2008 Laurent Ribon (laumaya@users.sourceforge.net)
 Version 1.1.0, packaged on March, 2009.

 http://glc-lib.sourceforge.net

 GLC-lib is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 GLC-lib is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with GLC-lib; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

 *****************************************************************************/

#ifndef GLC_DISTANCE_H_
#define GLC_DISTANCE_H_

#include <QList>
#include "../glc_object.h"
#include "../sceneGraph/glc_instance.h"

//////////////////////////////////////////////////////////////////////
//! \class GLC_Distance
/*! \brief GLC_Distance is the minimum distance between to elements*/

/*! GLC_Distance is used to compute the minimum distance between to Elements.
 */
//////////////////////////////////////////////////////////////////////
class GLC_Distance : public GLC_Object
{
//////////////////////////////////////////////////////////////////////
/*! @name Constructor / Destructor */
//@{
//////////////////////////////////////////////////////////////////////
public:
	//! Default constructor
	GLC_Distance();

	//! Construct a distmin with 2 GLC_Instance
	GLC_Distance(const GLC_Instance&, const GLC_Instance&);

	//! Copy Constructor
	GLC_Distance(const GLC_Distance&);

	//! Default destructor
	virtual ~GLC_Distance();
//@}



//////////////////////////////////////////////////////////////////////
/*! \name Set Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:
	//! Clear the 2 groups
	void clear();

	//! Add instance in group 1
	void addInstanceInGroup1(const GLC_Instance&);

	//! Add instances list in group 1
	void addInstancesInGroup1(const QList<GLC_Instance>&);

	//! Add instance in group 1
	void addInstanceInGroup2(const GLC_Instance&);

	//! Add instances list in group 1
	void addInstancesInGroup2(const QList<GLC_Instance>&);

	//! Compute the minimum distance between the 2 groups
	void computeMinimumDistance();

	//! Return the minimum distance between the 2 groups
	double distMin();

//@}

//////////////////////////////////////////////////////////////////////
/*! \private services functions*/
//@{
//////////////////////////////////////////////////////////////////////
private:
	//! Return distance mini beween to instance
	double minimumDistance(GLC_Instance&, GLC_Instance&) const;
//@}

//////////////////////////////////////////////////////////////////////
// Private members
//////////////////////////////////////////////////////////////////////
private:
	//! The first list of instance
	QList<GLC_Instance> m_ListOfInstances1;

	//! The Second list of instance
	QList<GLC_Instance> m_ListOfInstances2;

	//! The Minimum Distance point 1
	GLC_Point4d m_Point1;

	//! The Minimum Distance point 2
	GLC_Point4d m_Point2;

	//! The minimum distance
	double m_DistanceMini;


};

#endif /* GLC_DISTANCE_H_ */