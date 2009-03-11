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

//! \file glc_simplegeomengine.h Interface for the GLC_SimpleGeomEngine class.

#ifndef GLC_SIMPLEGEOMENGINE_H_
#define GLC_SIMPLEGEOMENGINE_H_

#include "glc_geomengine.h"

//! \struct GLC_Vertex
/*! \brief GLC_Vertex : OpenGL Vertex */
struct GLC_Vertex
{
	// Vertex
	float x, y, z;			// 12 Bytes
	// Normal
	float nx, ny, nz;		// 12 Bytes
	// Texture
	float s, t;				// 8 Bytes
	// Color
	GLfloat r, g, b, a;		// 16 Bytes
	// => 48 Bytes
};
//! QVector of GLC_Vertex
typedef QVector<GLC_Vertex> VertexVector;

//////////////////////////////////////////////////////////////////////
//! \class GLC_SimpleGeomEngine
/*! \brief GLC_SimpleGeomEngine : specialized engine
 */
//////////////////////////////////////////////////////////////////////
class GLC_SimpleGeomEngine : public GLC_GeomEngine
{
public:
	//! Default constructor
	GLC_SimpleGeomEngine();

	//! Copy constructor
	GLC_SimpleGeomEngine(const GLC_SimpleGeomEngine&);

	//! Destructor
	virtual ~GLC_SimpleGeomEngine();


//////////////////////////////////////////////////////////////////////
/*! \name Get Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:
	//! Return the Vertex Vector
	VertexVector vertexVector() const;

	//! Return the Vertex Vector handle
	inline VertexVector* vertexVectorHandle()
	{ return &m_VertexVector;}

	//! Return the Index Vector
	QVector<GLuint> indexVector() const;

	//! Return the Index Vector
	inline QVector<GLuint>* indexVectorHandle()
	{ return &m_IndexVector;}

//@}

//////////////////////////////////////////////////////////////////////
/*! \name OpenGL Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:
	//! Vbo creation
	virtual void createVBOs();

	//! Vbo Usage
	virtual void useVBOs(bool);
//@}

//////////////////////////////////////////////////////////////////////
// Protected members
//////////////////////////////////////////////////////////////////////
private:
	//! Vertex Vector
	VertexVector m_VertexVector;

	//! Index Vector
	QVector<GLuint> m_IndexVector;

	//! IBO ID
	GLuint m_IboId;

};

#endif /* GLC_SIMPLEGEOMENGINE_H_ */