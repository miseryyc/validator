/* This file was generated by PyBindGen 0.14.1 */
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stddef.h>


#if PY_VERSION_HEX < 0x020400F0

#define PyEval_ThreadsInitialized() 1

#define Py_CLEAR(op)				\
        do {                            	\
                if (op) {			\
                        PyObject *tmp = (PyObject *)(op);	\
                        (op) = NULL;		\
                        Py_DECREF(tmp);		\
                }				\
        } while (0)


#define Py_VISIT(op)							\
        do { 								\
                if (op) {						\
                        int vret = visit((PyObject *)(op), arg);	\
                        if (vret)					\
                                return vret;				\
                }							\
        } while (0)

#endif



#if PY_VERSION_HEX < 0x020500F0

typedef int Py_ssize_t;
# define PY_SSIZE_T_MAX INT_MAX
# define PY_SSIZE_T_MIN INT_MIN
typedef inquiry lenfunc;
typedef intargfunc ssizeargfunc;
typedef intobjargproc ssizeobjargproc;

#endif


#if     __GNUC__ > 2
# define PYBINDGEN_UNUSED(param) param __attribute__((__unused__))
#elif     __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
# define PYBINDGEN_UNUSED(param) __attribute__((__unused__)) param
#else
# define PYBINDGEN_UNUSED(param) param
#endif  /* !__GNUC__ */

typedef enum _PyBindGenWrapperFlags {
   PYBINDGEN_WRAPPER_FLAG_NONE = 0,
   PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED = (1<<0),
} PyBindGenWrapperFlags;


#include "peptide_fragment.h"
/* --- module functions --- */


PyObject *
_wrap_PeptideFragmentanalyze(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    char *peptide;
    const char *keywords[] = {"peptide", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s", (char **) keywords, &peptide)) {
        return NULL;
    }
    analyze(peptide);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}
PyObject * _wrap_PeptideFragmentanalyze(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);

static PyMethodDef PeptideFragment_functions[] = {
    {(char *) "analyze", (PyCFunction) _wrap_PeptideFragmentanalyze, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
#if defined(__GNUC__) && __GNUC__ >= 4
__attribute__ ((visibility("default")))
#endif
initPeptideFragment(void)
{
    PyObject *m;
    m = Py_InitModule3((char *) "PeptideFragment", PeptideFragment_functions, NULL);
    if (m == NULL) {
        return;
    }
}
