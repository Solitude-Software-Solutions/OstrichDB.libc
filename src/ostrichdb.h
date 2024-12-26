#ifndef OSTRICHDB_H
#define OSTRICHDB_H

//=========================================================//
// Author: Marshall A Burns aka @SchoolyB
//
// Copyright 2024 Marshall A Burns and Solitude Software Solutions LLC
// Licensed under MIT License (see LICENSE file for details)
//=========================================================//

#include <stdarg.h> // Standard library for va_list, va_start, va_end, and va_arg

// Function to run the build script for OstrichDB
int ost_build(void);

// Function to restart the OstrichDB without rebuilding
int ost_restart(void);

// Sets admin credentials by passing the username and password to the command line
int ost_login(const char* username, const char* password);

// Creates a new collection, cluster, or record depending on the objType
int ost_new(const char* objType, const char* objName);

// Erases a collection, cluster, or record depending on the objType
int ost_delete(const char* objType, const char* objName);

// Renames a collection, cluster, or record
int ost_rename(const char* objType, const char* oldName, const char* newName);

// Fetches and returns the object of the given type and name as a string
const char* ost_fetch(const char* objType, const char* objName);

// Sets the value of a record, ensuring the value matches the record type
int ost_set_value(const char* recordName, const char* value);

// Splits the value of an array record by ',' and returns a single element
const char* ost_split_array_value(const char* recordName, int index);

#endif // OSTRICHDB_H