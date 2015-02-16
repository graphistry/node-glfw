/*
 * common.h
 *
 */

#ifndef COMMON_H_
#define COMMON_H_

// OpenGL Graphics Includes
#define GLEW_STATIC
#include <GL/glew.h>

#define GLFW_NO_GLU
#define GLFW_DLL
#include <GLFW/glfw3.h>

// NodeJS includes
#include <node.h>
#include "nan.h"

using namespace v8;

namespace {
#define JS_STR(...) NanNew<v8::String>(__VA_ARGS__)
#define JS_INT(val) NanNew<v8::Integer>(val)
#define JS_NUM(val) NanNew<v8::Number>(val)
#define JS_BOOL(val) NanNew<v8::Boolean>(val)
#define JS_RETHROW(tc) v8::Local<v8::Value>::New(tc.Exception());

#define REQ_ARGS(N)                                                     \
  if (args.Length() < (N))                                              \
    NanThrowTypeError("Expected " #N " arguments");

#define REQ_STR_ARG(I, VAR)                                             \
  if (args.Length() <= (I) || !args[I]->IsString())                     \
    NanThrowTypeError("Argument " #I " must be a string");              \
  String::Utf8Value VAR(args[I]->ToString());

#define REQ_EXT_ARG(I, VAR)                                             \
  if (args.Length() <= (I) || !args[I]->IsExternal())                   \
    NanThrowTypeError("Argument " #I " invalid");                       \
  Local<External> VAR = Local<External>::Cast(args[I]);

#define REQ_FUN_ARG(I, VAR)                                             \
  if (args.Length() <= (I) || !args[I]->IsFunction())                   \
    NanThrowTypeError("Argument " #I " must be a function");            \
  Local<Function> VAR = Local<Function>::Cast(args[I]);

#define REQ_ERROR_THROW(error) if (ret == error) NanThrowError(String::New(#error));

}
#endif /* COMMON_H_ */
