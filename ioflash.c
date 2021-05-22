#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "dbg.h"

typedef enum ioFunc {
    FSCANF_FUNC, FGETS_FUNC, FOPEN_FUNC, FREOPEN_FUNC,
    FDOPEN_FUNC, FCLOSE_FUNC, FCLOSEALL_FUNC, FGETPOS_FUNC,
    FSEEK_FUNC, FTELL_FUNC, REWIND_FUNC, FPRINTF_FUNC,
    FWRITE_FUNC, FREAD_FUNC, OTHER_FUNC
} ioFunc;

const char IO_REFS[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n' 
};

const char *IO_FUNC_NAMES[] = {
    "fscanf", "fgets", "fopen", "freopen", "fdopen",
    "fclose", "fcloseall", "fgetpos", "fseek", "ftell",
    "rewind", "fprintf", "fwrite", "fread"
};


typedef struct Function {
    char *name;
    char *description;
} Function;

const char *IO_FUNC_DESCRIPTIONS[] = {
    "fscanf\n"\
    "int fscanf(FILE *stream, const char *format, ...)\n"\
    "reads input from stream pointer stream\n",

    "fgets\n"\
    "char *fgets(char *s, int size, FILE *stream)\n"\
    "reads in at most one less than size characters from stream\n"\
    "and stores them into the buffer pointed to by s\n",

    "fopen\n"\
    "FILE fopen( char *pathname,  char* mode)\n"
    "opens the file whose name is the string pointed to by pathname\n"
    "and associates a stream with it.\n"
    "options : {\n"
    "\tr: read\n"
    "\tr+: read/write\n"
    "\tw: truncate zero and write\n"
    "\tw+: open for r/w, create and trunc zero\n"
    "\ta: open for append, create if none stream pos end\n"
    "\ta+: open for read and append, create if none, stream pos end\n"
    "}\n",
    
    "freopen\n"\
    "freopen( char *pathname,  char *mode,FILE *stream)\n"\
    "opens the file whose name is the string pointed to by pathname\n"
    "and associates the stream pointed to by stream with it.\n"
    "The originam stream (if it exists) is closed.\n"
    "The mode argument is used just as in the fopen() function.\n",

    "fdopen\n"\
    "FILE *fdopen(int fd,  char *mode)\n"
    "associates a stream with the existing file descriptor.\n"
    "the mode of the stream (r, r+, w, w+, a, a+) must be\n"
    "compatible with the mode of the file descriptor.\n"
    "the file position indicator for the new stream is set to\n"
    "that belonging to fd, and the error and EOF indicators are cleared.\n"
    "Modes w or w+ do not cause truncation of the file. The file descriptor\n"
    "is not dup'ed, and will close with the stream created by fdopen()\n"
    "The result of applying fdopen to a shared memory obj is undefined\n",

    "fclose\n"\
    "int fclose(FILE +stream)\n"
    "flushes thre stream pointed to by stream (writing any buffered output\n"
    "data using fflush and closes the underlying file descriptor.\n",

    "fcloseall\n"\
    "int fcloseall(void)\n"
    "closes all of the calling process's open streams.\n"
    "Buffered output for each stream is written before it is closed\n"
    "(as is for fflush(3); buffered input is discarded.\n",

    "fgetpos\n"\
    "int fgetpos(FILE *stream, fpos_t *pos)\n"\
    "alternate to fsetpos() and equivalent to ftell() and fseek(),\n"\
    "setting and storing the current value of the file offset into or from the\n"\
    "object referenced by pos. May be a complex object on some non-UNIX systems\n",

    "fseek\n"\
    "int fseek(FILE *stream, long offset, int whence)\n"\
    "sets the file position indicator for the stream pointed to by stream.\n"\
    "The new position, measured in bytes, is obtained by adding offset bytes\n"\
    "to the position specifified by whence. If whence is set to SEEK_SET,\n"\
    "SEEK_CUR or SEEK_END, the offset is relative to the start of the file,\n"\
    "the current position indicator, or EOF, respectively. A successful call\n"\
    "to the fseek() function clears the EOF indicator for the stream and\n"\
    "undoes any effects of the ungetc(3) function on the same stream.\n", 

    "ftell\n"\
    "long ftell(FILE *stream)\n"\
    "obtains the current value of the file position indicator for the stream\n"\
    "pointed to by stream.\n",

    "rewind\n"\
    "void rewind(FILE *stream)\n"\
    "sets the file position indicator for the stream pointed to by stream\n"\
    "to the beginning of the file, equivalent to:\n"\
    "(void) fseek(stream, 0L, SEEK_SET)\n"\
    "except that the error indicator for the stream is also cleared.\n",

    "fprintf\n"\
    "int fprintf(FILE *stream, const char *format, ...)\n"\
    "writes the output to the stream specified by stream, in the format\n"\
    "specified by format, see man pages for more details on format\n",

    "fwrite\n"
    "size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)\n"\
    "writes nmemb items of data, each size bytes long, from the stream pointed\n"\
    "to by stream, storing them at the location given py ptr.\n",

    "fread\n"\
    "size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)\n"\
    "reads nmemb items of data, each size bytes long, from the stream\n"\
    "pointed to by stream, storing them at the location given by ptr.\n"
};

void printdef(int funcnum)
{
    printf("%s", IO_FUNC_DESCRIPTIONS[funcnum]);
}

int getflashcard()
{
    int i = 0;
    printf("Can you remember what each function does?\n");
    for(i = 0; i <= OTHER_FUNC - 1; i++) {  // all but the last flash, NULL
        printf("%c) %s\n", IO_REFS[i], IO_FUNC_NAMES[i]);
    }
    printf("> ");

    char ch = getchar();
    getchar(); // eat ENTER

    switch (ch) {
        case -1:
            printf("Giving up? You suck beans.\n");
            return 0;
            break;
        case 'a': printdef(0); break;
        case 'b': printdef(1); break;
        case 'c': printdef(2); break;
        case 'd': printdef(3); break;
        case 'e': printdef(4); break;
        case 'f': printdef(5); break;
        case 'g': printdef(6); break;
        case 'h': printdef(7); break;
        case 'i': printdef(8); break;
        case 'j': printdef(9); break;
        case 'k': printdef(10); break;
        case 'l': printdef(11); break;
        case 'm': printdef(12); break;
        case 'n': printdef(13); break;

        default: printf("select a valid option!\n"\
                         "> ");
    }
    return 1;
}

int process_input()
{
    char ch = getchar();
    getchar(); // eat ENTER

    switch (ch) {
        case -1:
            printf("Giving up? You suck beans.\n");
            return 0;
            break;

        case 'f':
            getflashcard();
            break;

        default:
            printf("Hit f to display an unanswered flashcard: \n"
            "> ");
    }
    return 1;
}

int main(int argc, char *argv[])
{
    printf("Welcome to io and filestream flashcards\n"\
        "the process will run until it receives a kill message");

    while(process_input()) {
    }
    
    return 0;
}
