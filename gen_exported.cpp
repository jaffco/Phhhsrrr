#include "gen_exported.h"

namespace gen_exported {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	int __exception;
	int vectorsize;
	t_sample m_history_9;
	t_sample m_history_8;
	t_sample m_history_7;
	t_sample m_history_10;
	t_sample m_history_12;
	t_sample m_history_11;
	t_sample m_history_13;
	t_sample m_history_6;
	t_sample m_history_4;
	t_sample samplerate;
	t_sample m_history_5;
	t_sample m_phase_1;
	t_sample m_history_3;
	t_sample m_rate_2;
	t_sample m_history_14;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_phase_1 = ((int)0);
		m_rate_2 = ((t_sample)0.5);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample c1 = ((samplerate * ((t_sample)0.25)) * ((t_sample)0.083333333333333));
		t_sample c2 = ((samplerate * ((t_sample)0.25)) * ((t_sample)0.1));
		t_sample c3 = ((samplerate * ((t_sample)0.25)) * ((t_sample)0.125));
		t_sample c4 = ((samplerate * ((t_sample)0.25)) * ((t_sample)0.16666666666667));
		t_sample c5 = ((samplerate * ((t_sample)0.25)) * ((t_sample)0.25));
		t_sample c6 = ((samplerate * ((t_sample)0.25)) * ((t_sample)0.5));
		int max_15 = (samplerate * ((t_sample)0.25));
		int max_16 = (samplerate * ((t_sample)0.25));
		int max_17 = (samplerate * ((t_sample)0.25));
		int max_18 = (samplerate * ((t_sample)0.25));
		int max_19 = (samplerate * ((t_sample)0.25));
		int max_20 = (samplerate * ((t_sample)0.25));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			m_phase_1 = (m_phase_1 + safediv(m_rate_2, samplerate));
			m_phase_1 = safemod(m_phase_1, ((int)1));
			t_sample lfo = fabs(((m_phase_1 * ((int)2)) - ((int)1)));
			t_sample Fc1 = (c1 + (lfo * (c1 * ((t_sample)0.5))));
			t_sample Fc2 = (c2 + (lfo * (c2 * ((t_sample)0.5))));
			t_sample Fc3 = (c3 + (lfo * (c3 * ((t_sample)0.5))));
			t_sample Fc4 = (c4 + (lfo * (c4 * ((t_sample)0.5))));
			t_sample Fc5 = (c5 + (lfo * (c5 * ((t_sample)0.5))));
			t_sample Fc6 = (c6 + (lfo * (c6 * ((t_sample)0.5))));
			t_sample expr_1140 = Fc1;
			t_sample expr_1141 = Fc2;
			t_sample expr_1142 = Fc3;
			t_sample expr_1143 = Fc4;
			t_sample expr_1144 = Fc5;
			t_sample expr_1145 = Fc6;
			t_sample abs_74 = fabs(expr_1140);
			t_sample clamp_63 = ((abs_74 <= ((int)0)) ? ((int)0) : ((abs_74 >= max_15) ? max_15 : abs_74));
			t_sample mul_73 = (clamp_63 * safediv(3.1415926535898, samplerate));
			t_sample tan_72 = tan(mul_73);
			t_sample add_70 = (tan_72 + ((int)1));
			t_sample div_71 = safediv(tan_72, add_70);
			t_sample gen_76 = div_71;
			t_sample add_65 = (div_71 + ((int)1));
			t_sample gen_77 = add_65;
			t_sample mul_69 = (div_71 * div_71);
			t_sample mul_68 = (div_71 * ((int)1));
			t_sample add_67 = ((mul_68 + mul_69) + ((int)1));
			t_sample rdiv_66 = safediv(((int)1), add_67);
			t_sample gen_75 = rdiv_66;
			t_sample mul_80 = (m_history_3 * gen_77);
			t_sample sub_84 = (in1 - (m_history_4 + mul_80));
			t_sample mul_83 = (sub_84 * gen_75);
			t_sample mul_62 = (mul_83 * gen_76);
			t_sample add_61 = (mul_62 + m_history_3);
			t_sample gen_89 = add_61;
			t_sample add_59 = (mul_62 + add_61);
			t_sample mul_82 = (add_61 * gen_76);
			t_sample add_81 = (mul_82 + m_history_4);
			t_sample add_78 = (mul_82 + add_81);
			t_sample history_60_next_85 = fixdenorm(add_59);
			t_sample history_79_next_86 = fixdenorm(add_78);
			t_sample div_95 = (gen_89 * ((t_sample)1));
			t_sample mul_91 = (div_95 * ((int)2));
			t_sample sub_92 = (in1 - mul_91);
			t_sample gen_103 = sub_92;
			t_sample abs_1151 = fabs(expr_1141);
			t_sample clamp_1168 = ((abs_1151 <= ((int)0)) ? ((int)0) : ((abs_1151 >= max_16) ? max_16 : abs_1151));
			t_sample mul_1171 = (clamp_1168 * safediv(3.1415926535898, samplerate));
			t_sample tan_1173 = tan(mul_1171);
			t_sample add_1172 = (tan_1173 + ((int)1));
			t_sample div_1150 = safediv(tan_1173, add_1172);
			t_sample gen_1164 = div_1150;
			t_sample add_1165 = (div_1150 + ((int)1));
			t_sample gen_1146 = add_1165;
			t_sample mul_1159 = (div_1150 * div_1150);
			t_sample mul_1153 = (div_1150 * ((int)1));
			t_sample add_1163 = ((mul_1153 + mul_1159) + ((int)1));
			t_sample rdiv_1156 = safediv(((int)1), add_1163);
			t_sample gen_1178 = rdiv_1156;
			t_sample mul_1181 = (m_history_5 * gen_1146);
			t_sample sub_1166 = (gen_103 - (m_history_6 + mul_1181));
			t_sample mul_1167 = (sub_1166 * gen_1178);
			t_sample mul_1177 = (mul_1167 * gen_1164);
			t_sample add_1161 = (mul_1177 + m_history_5);
			t_sample gen_1182 = add_1161;
			t_sample add_1152 = (mul_1177 + add_1161);
			t_sample mul_1176 = (add_1161 * gen_1164);
			t_sample add_1162 = (mul_1176 + m_history_6);
			t_sample add_1170 = (mul_1176 + add_1162);
			t_sample history_60_next_1179 = fixdenorm(add_1152);
			t_sample history_79_next_1180 = fixdenorm(add_1170);
			t_sample div_1157 = (gen_1182 * ((t_sample)1));
			t_sample mul_1147 = (div_1157 * ((int)2));
			t_sample sub_1169 = (gen_103 - mul_1147);
			t_sample gen_137 = sub_1169;
			t_sample abs_1191 = fabs(expr_1142);
			t_sample clamp_1220 = ((abs_1191 <= ((int)0)) ? ((int)0) : ((abs_1191 >= max_17) ? max_17 : abs_1191));
			t_sample mul_1212 = (clamp_1220 * safediv(3.1415926535898, samplerate));
			t_sample tan_1214 = tan(mul_1212);
			t_sample add_1213 = (tan_1214 + ((int)1));
			t_sample div_1190 = safediv(tan_1214, add_1213);
			t_sample gen_1205 = div_1190;
			t_sample add_1206 = (div_1190 + ((int)1));
			t_sample gen_1186 = add_1206;
			t_sample mul_1199 = (div_1190 * div_1190);
			t_sample mul_1193 = (div_1190 * ((int)1));
			t_sample add_1203 = ((mul_1193 + mul_1199) + ((int)1));
			t_sample rdiv_1196 = safediv(((int)1), add_1203);
			t_sample gen_1218 = rdiv_1196;
			t_sample mul_1221 = (m_history_7 * gen_1186);
			t_sample sub_1207 = (gen_137 - (m_history_8 + mul_1221));
			t_sample mul_1208 = (sub_1207 * gen_1218);
			t_sample mul_1209 = (mul_1208 * gen_1205);
			t_sample add_1201 = (mul_1209 + m_history_7);
			t_sample gen_1222 = add_1201;
			t_sample add_1192 = (mul_1209 + add_1201);
			t_sample mul_1217 = (add_1201 * gen_1205);
			t_sample add_1202 = (mul_1217 + m_history_8);
			t_sample add_1211 = (mul_1217 + add_1202);
			t_sample history_60_next_1204 = fixdenorm(add_1192);
			t_sample history_79_next_1219 = fixdenorm(add_1211);
			t_sample div_1197 = (gen_1222 * ((t_sample)1));
			t_sample mul_1187 = (div_1197 * ((int)2));
			t_sample sub_1210 = (gen_137 - mul_1187);
			t_sample gen_163 = sub_1210;
			t_sample abs_1228 = fabs(expr_1143);
			t_sample clamp_1255 = ((abs_1228 <= ((int)0)) ? ((int)0) : ((abs_1228 >= max_18) ? max_18 : abs_1228));
			t_sample mul_1257 = (clamp_1255 * safediv(3.1415926535898, samplerate));
			t_sample tan_1241 = tan(mul_1257);
			t_sample add_1258 = (tan_1241 + ((int)1));
			t_sample div_1248 = safediv(tan_1241, add_1258);
			t_sample gen_1238 = div_1248;
			t_sample add_1252 = (div_1248 + ((int)1));
			t_sample gen_1246 = add_1252;
			t_sample mul_1233 = (div_1248 * div_1248);
			t_sample mul_1230 = (div_1248 * ((int)1));
			t_sample add_1237 = ((mul_1230 + mul_1233) + ((int)1));
			t_sample rdiv_1259 = safediv(((int)1), add_1237);
			t_sample gen_1262 = rdiv_1259;
			t_sample mul_1244 = (m_history_9 * gen_1246);
			t_sample sub_1253 = (gen_163 - (m_history_10 + mul_1244));
			t_sample mul_1254 = (sub_1253 * gen_1262);
			t_sample mul_1251 = (mul_1254 * gen_1238);
			t_sample add_1236 = (mul_1251 + m_history_9);
			t_sample gen_1250 = add_1236;
			t_sample add_1229 = (mul_1251 + add_1236);
			t_sample mul_1249 = (add_1236 * gen_1238);
			t_sample add_1263 = (mul_1249 + m_history_10);
			t_sample add_1240 = (mul_1249 + add_1263);
			t_sample history_60_next_1239 = fixdenorm(add_1229);
			t_sample history_79_next_1234 = fixdenorm(add_1240);
			t_sample div_1260 = (gen_1250 * ((t_sample)1));
			t_sample mul_1226 = (div_1260 * ((int)2));
			t_sample sub_1256 = (gen_163 - mul_1226);
			t_sample gen_189 = sub_1256;
			t_sample abs_1268 = fabs(expr_1144);
			t_sample clamp_1300 = ((abs_1268 <= ((int)0)) ? ((int)0) : ((abs_1268 >= max_19) ? max_19 : abs_1268));
			t_sample mul_1296 = (clamp_1300 * safediv(3.1415926535898, samplerate));
			t_sample tan_1278 = tan(mul_1296);
			t_sample add_1298 = (tan_1278 + ((int)1));
			t_sample div_1286 = safediv(tan_1278, add_1298);
			t_sample gen_1303 = div_1286;
			t_sample add_1292 = (div_1286 + ((int)1));
			t_sample gen_1283 = add_1292;
			t_sample mul_1285 = (div_1286 * div_1286);
			t_sample mul_1297 = (div_1286 * ((int)1));
			t_sample add_1275 = ((mul_1297 + mul_1285) + ((int)1));
			t_sample rdiv_1290 = safediv(((int)1), add_1275);
			t_sample gen_1302 = rdiv_1290;
			t_sample mul_1281 = (m_history_11 * gen_1283);
			t_sample sub_1291 = (gen_189 - (m_history_12 + mul_1281));
			t_sample mul_1293 = (sub_1291 * gen_1302);
			t_sample mul_1294 = (mul_1293 * gen_1303);
			t_sample add_1274 = (mul_1294 + m_history_11);
			t_sample gen_1289 = add_1274;
			t_sample add_1269 = (mul_1294 + add_1274);
			t_sample mul_1287 = (add_1274 * gen_1303);
			t_sample add_1301 = (mul_1287 + m_history_12);
			t_sample add_1277 = (mul_1287 + add_1301);
			t_sample history_60_next_1276 = fixdenorm(add_1269);
			t_sample history_79_next_1272 = fixdenorm(add_1277);
			t_sample div_1288 = (gen_1289 * ((t_sample)1));
			t_sample mul_1266 = (div_1288 * ((int)2));
			t_sample sub_1295 = (gen_189 - mul_1266);
			t_sample gen_215 = sub_1295;
			t_sample abs_1309 = fabs(expr_1145);
			t_sample clamp_1332 = ((abs_1309 <= ((int)0)) ? ((int)0) : ((abs_1309 >= max_20) ? max_20 : abs_1309));
			t_sample mul_1338 = (clamp_1332 * safediv(3.1415926535898, samplerate));
			t_sample tan_1320 = tan(mul_1338);
			t_sample add_1339 = (tan_1320 + ((int)1));
			t_sample div_1327 = safediv(tan_1320, add_1339);
			t_sample gen_1317 = div_1327;
			t_sample add_1334 = (div_1327 + ((int)1));
			t_sample gen_1325 = add_1334;
			t_sample mul_1333 = (div_1327 * div_1327);
			t_sample mul_1331 = (div_1327 * ((int)1));
			t_sample add_1316 = ((mul_1331 + mul_1333) + ((int)1));
			t_sample rdiv_1340 = safediv(((int)1), add_1316);
			t_sample gen_1343 = rdiv_1340;
			t_sample mul_1323 = (m_history_13 * gen_1325);
			t_sample sub_1307 = (gen_215 - (m_history_14 + mul_1323));
			t_sample mul_1335 = (sub_1307 * gen_1343);
			t_sample mul_1336 = (mul_1335 * gen_1317);
			t_sample add_1315 = (mul_1336 + m_history_13);
			t_sample add_1310 = (mul_1336 + add_1315);
			t_sample mul_1328 = (add_1315 * gen_1317);
			t_sample add_1342 = (mul_1328 + m_history_14);
			t_sample gen_1308 = add_1342;
			t_sample add_1319 = (mul_1328 + add_1342);
			t_sample history_60_next_1318 = fixdenorm(add_1310);
			t_sample history_79_next_1313 = fixdenorm(add_1319);
			t_sample out1 = (gen_1308 + in1);
			m_history_3 = history_60_next_85;
			m_history_14 = history_79_next_1313;
			m_history_13 = history_60_next_1318;
			m_history_12 = history_79_next_1272;
			m_history_11 = history_60_next_1276;
			m_history_10 = history_79_next_1234;
			m_history_9 = history_60_next_1239;
			m_history_8 = history_79_next_1219;
			m_history_7 = history_60_next_1204;
			m_history_6 = history_79_next_1180;
			m_history_5 = history_60_next_1179;
			m_history_4 = history_79_next_86;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			
		};
		return __exception;
		
	};
	inline void set_rate(t_param _value) {
		m_rate_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 1;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 1; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_rate(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_rate_2; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(1 * sizeof(ParamInfo));
	self->__commonstate.numparams = 1;
	// initialize parameter 0 ("m_rate_2")
	pi = self->__commonstate.params + 0;
	pi->name = "rate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_rate_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // gen_exported::
