#ifndef __FACTORY_HPP_INCLUDED__
#define __FACTORY_HPP_INCLUDED__

#include "CIntN.h"
#include "CIntN0.h"
#include "CIntN1.h"

class Factory
{
	public:
		virtual CIntN* create() = 0;
		virtual CIntN* create(string file_name, size_t N, string num) = 0;
		virtual CIntN* create(const CIntN& other) = 0;
};

class Factory_hori : public Factory
{
	public:
		CIntN* create() override { return new CIntN0(); }
		CIntN* create(string file_name, size_t N, string num) override { return new CIntN0(file_name,  N,  num); }
		CIntN* create(const CIntN& other) override { return new CIntN0( other); }
};

class Factory_vert : public Factory
{
	public:
		CIntN* create() override { return new CIntN1(); }
		CIntN* create(string file_name, size_t N, string num) override { return new CIntN1(file_name, N, num); }
		CIntN* create(const CIntN& other) override { return new CIntN1(other); }
};


#endif 