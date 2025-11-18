/*******************************************************
 * CS 2130 Homework 8
 * Fall 2025 - Simplified File System 
 *******************************************************/

#ifndef __FILESYSTEM_H
#define __FILESYSTEM_H

/**
 * A file node.
 *
 * Contains the name of the file, the file size (in bytes), a pointer to
 * the directory containing this file, and a pointer to the next file in
 * the list of files in the directory.
 */
typedef struct file_node_s {
  const char *name;
  struct dir_node_s *parent;
  struct file_node_s *next;
  int size;
} file_node;

/** 
 * A directory node.
 *
 * Contains the name of the directory, a pointer to the directory
 * containing this directory, a pointer to a list of subdirectories,
 * and a pointer to a list of files in this directory.
 */
typedef struct dir_node_s {
    const char *name;
    struct dir_node_s *parent;
    struct dir_node_s *next;
    struct dir_node_s *subdirs;
    struct file_node_s *files;
} dir_node;

// TODO Implement these functions

/**
 * Creates a new directory struct in memory with the given name and returns
 * a pointer to that directory.  If the provided name is NULL, instead
 * returns NULL. 
 */
dir_node *create_dir(const char *name);


/**
 * Returns a pointer to the highest-level directory, given a pointer to either
 * a directory node or a file node. That is, follow the parent pointer until it
 * is `NULL`.  If the provided pointer is `NULL`, instead returns `NULL`.
 */
dir_node *root_dir(void *node);

/**
 * Returns a pointer to the first file in the directory, given a pointer to 
 * any directory node. If the provided pointer is `NULL`, instead returns `NULL`.
 */
file_node *first_file(dir_node *dir);

/**
 * Returns a pointer to the last node file in the directory, given a pointer 
 * any directory node. If the provided pointer is `NULL`, instead returns `NULL`. 
 */
file_node *last_file(dir_node *dir);

/**
 * Returns the number of entries in the directory, given a pointer to any
 * directory node.  The number of entries is the sum of the number of files
 * plus the number of subdirectories.  If the provided pointer is `Null`,
 * return 0.
 */
unsigned long dir_entries(dir_node *dir);

/**
 * Returns the pointer to a file node in the directory with the given
 * name.  If the provided directory or name pointers are `NULL`, instead
 * returns `NULL`.  If no file is found, returns `NULL`.
 */
file_node *find_file(dir_node *dir, const char *name);


/**
 * Returns the pointer to a sub-directory node in the directory with the given
 * name.  If the provided directory or name pointers are `NULL`, instead
 * returns `NULL`.  If no directory is found, returns `NULL`.
 */
dir_node *find_dir(dir_node *dir, const char *name);

/**
 * Given a pointer to a directory node and a file node, remove that file from the list
 * of files in that directory, `free`ing its memory in the process. Returns a pointer 
 * to the node that now occupies the same position in the list that the removed node 
 * used to occupy.
 * 
 * If given `NULL`, this function does nothing and returns `NULL`.
 */
file_node *remove_file(dir_node *dir, file_node *file);


/**
 * Given a pointer to a directory node and a sub-directory node, remove that subdirectory 
 * from the list of sub-directories in that directory, `free`ing its memory in 
 * the process.  The sub-directory's sub-directories should be added as sub-directories
 * at the end of the directory node's list of sub-directories and the sub-directory's 
 * files should be added as files at the end directory node's list of files.
 *
 * Returns a pointer to the node that now occupies the same position in the list that 
 * the removed node used to occupy.
 * 
 * If given `NULL`, this function does nothing and returns `NULL`.
 */
dir_node *remove_dir(dir_node *dir, dir_node *subdir);

/**
 * Extend a directory's list of files by one by adding a new file node with the
 * given name and file size to the head (beginning) of the file list (if `after` is NULL).
 * If `after` is not `NULL`, it inserts the new file immediately following the node 
 * with `name` matching `after`.  If no file matching the name `after` is found, it inserts
 * the new file at the end of the list of files. 
 * 
 * If either `dir` or `name` is `NULL`, it returns `NULL` and does not change any file list. 
 * In all cases, the new node is allocated using `malloc` 
 * and returned by the function.
 */
file_node *insert_file(dir_node *dir, const char *name, int size, const char *after);

/**
 * Extend a directory's list of sub-directories by one by adding a new directory node 
 * with the given name to the head (beginning) of the sub-directory list (if `after` is 
 * NULL). If `after` is not `NULL`, it inserts the new directory immediately following 
 * the node with `name` matching `after`.  If no directory matching the name `after` 
 * is found, it inserts the new directory at the end of the list of sub-directories. 
 * 
 * If either `dir` or `name` is `NULL`, it returns `NULL` and does not change any 
 * sub-directory list. In all cases, the new node is allocated using `malloc` 
 * and returned by the function.
 */
dir_node *insert_dir(dir_node *dir, const char *name, const char *after);



// The following function has been provided for you

/**
 * Displays the contents of the directory structure rooted at the given node
 * pointed to by `root` (recursively), pretty-printed to show hierarchy.
 */
void directory_list(dir_node *root, int indent);


#endif /* ifdef __FILESYSTEM_H */
