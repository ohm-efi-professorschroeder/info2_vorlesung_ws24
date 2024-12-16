#include "namesarchive.h"
#include "../../Termin_10/stringbst.h"

#include <string.h>

static StringBSTNode_t *root = NULL;

int addName(const char *name)
{
    root = insert(root, name);
    if(root)
        return 1;
    return 0;
}

int removeName(const char *name)
{
    if(findString(root, name))
    {
        root = delete(root, name);
        return 1;
    }

    return 0;
}

void printNames()
{
    if (root == NULL)
        return;

    inorderTraversal(root);
}

void clearArchive()
{
    freeBST(&root);
}


int loadArchive(const char *path)
{
    FILE* f;
    if ((f = fopen(path, "r")) != NULL) {
        char buffer[MAX_NAME_LEN];
        while (fgets(buffer, MAX_NAME_LEN, f)) {
            if (buffer[strlen(buffer)-1] == '\n')
                buffer[strlen(buffer)-1] = '\0';

            root = insert(root, buffer);
        }
        fclose(f);
        return 1;
    }
    return 0;
}

static void writeTree(const StringBSTNode_t *root, FILE* f)
{
    if(root != 0 && f != 0) {
        writeTree(root->left, f);
        fprintf(f, "%s\n", root->string);
        writeTree(root->right, f);
    }
}


int saveArchive(const char *path)
{
    FILE* f;
    if ((f = fopen(path, "w")) != NULL) {
        writeTree(root, f);
        fclose(f);
        return 1;
    }
    return 0;
}
// TODO Ende