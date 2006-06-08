/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005-2006 Laurent Ribon (laumaya@users.sourceforge.net)
 Version 0.9.6, packaged on June, 2006.

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

//! \file glc_openglexception.h Interface for the GLC_OpenGlException class.

#ifndef GLC_OPENGLEXCEPTION_H_
#define GLC_OPENGLEXCEPTION_H_

#include <QtOpenGL>
#include "glc_exception.h"

//////////////////////////////////////////////////////////////////////
//! \class GLC_OpenGlException
/*! \brief GLC_OpenGlException : Class for all OpenGL error
 */
//////////////////////////////////////////////////////////////////////

class GLC_OpenGlException : public GLC_Exception
{
//////////////////////////////////////////////////////////////////////
/*! @name Constructor / Destructor */
//@{
//////////////////////////////////////////////////////////////////////
public:
	//! Default constructor
	GLC_OpenGlException(const std::string& message, GLenum glError);
	
	//! Destructor
	virtual ~GLC_OpenGlException() throw();
//@}

//////////////////////////////////////////////////////////////////////
/*! \name Get Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:	
	//! Return exception description
	virtual const char* what() const throw();
//@}

//////////////////////////////////////////////////////////////////////
// protected members
//////////////////////////////////////////////////////////////////////
protected:
	
	//! Opengl Error description
	std::string m_GlErrorDescription;

};

#endif /*GLC_OPENGLEXCEPTION_H_*/