/*******************************************************************************
 * super.h
 *
 * This module contains all defines, typedefs, and prototypes for SUPEREL.CPP.
 *
 * ---------------------------------------------------------------------------
 * Persistence of Vision Ray Tracer ('POV-Ray') version 3.7.
 * Copyright 1991-2013 Persistence of Vision Raytracer Pty. Ltd.
 *
 * POV-Ray is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * POV-Ray is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ---------------------------------------------------------------------------
 * POV-Ray is based on the popular DKB raytracer version 2.12.
 * DKBTrace was originally written by David K. Buck.
 * DKBTrace Ver 2.0-2.12 were written by David K. Buck & Aaron A. Collins.
 * ---------------------------------------------------------------------------
 * $File: //depot/povray/smp/source/backend/shape/super.h $
 * $Revision: #22 $
 * $Change: 6164 $
 * $DateTime: 2013/12/09 17:21:04 $
 * $Author: clipka $
 *******************************************************************************/

#ifndef SUPER_H
#define SUPER_H

#include "backend/scene/objects.h"

namespace pov
{

/*****************************************************************************
* Global preprocessor definitions
******************************************************************************/

#define SUPERELLIPSOID_OBJECT (BASIC_OBJECT)



/*****************************************************************************
* Global typedefs
******************************************************************************/

class Superellipsoid : public ObjectBase
{
	public:
		Vector3d Power;

		Superellipsoid();
		virtual ~Superellipsoid();

		virtual ObjectPtr Copy();

		virtual bool All_Intersections(const Ray&, IStack&, TraceThreadData *);
		virtual bool Inside(const Vector3d&, TraceThreadData *) const;
		virtual void Normal(Vector3d&, Intersection *, TraceThreadData *) const;
		virtual void Translate(const Vector3d&, const TRANSFORM *);
		virtual void Rotate(const Vector3d&, const TRANSFORM *);
		virtual void Scale(const Vector3d&, const TRANSFORM *);
		virtual void Transform(const TRANSFORM *);
		virtual void Compute_BBox();
	protected:
		bool Intersect(const BasicRay& ray, IStack& Depth_Stack, TraceThreadData *Thread);
		static bool intersect_box(const Vector3d& P, const Vector3d& D, DBL *dmin, DBL *dmax);
		static DBL power(DBL x, DBL e);
		static DBL evaluate_g(DBL x, DBL y, DBL e);
		DBL evaluate_superellipsoid(const Vector3d& P) const;
		static int compdists(const void *in_a, const void *in_b);
		int find_ray_plane_points(const Vector3d& P, const Vector3d& D, int cnt, DBL *dists, DBL mindist, DBL maxdist) const;
		void solve_hit1(DBL v0, const Vector3d& tP0, DBL v1, const Vector3d& tP1, Vector3d& P) const;
		bool check_hit2(const Vector3d& P, const Vector3d& D, DBL t0, Vector3d& P0, DBL v0, DBL t1, DBL *t, Vector3d& Q) const;
		bool insert_hit(const BasicRay& ray, DBL Depth, IStack& Depth_Stack, TraceThreadData *Thread);
};

}

#endif
