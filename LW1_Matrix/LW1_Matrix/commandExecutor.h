#include <fstream>
#include <string>
#include "matrix.h"

struct Variable {
    std::string name;
    Matrix value;
};

struct Command{
    Variable *operand[2];
    Variable *result;
    int action;
    enum {SET=0, ADDITION=1, SUBTRACTION=2, TRANSPOSE=3, PRINT=4};
};

class CommandExecutor {
public:
    CommandExecutor();
    CommandExecutor(const char *fileName);
    void ExecScript();
    void OpenFile(const char *fileName);
    ~CommandExecutor();
private:
    Command _parsedCommand;
    std::ifstream _file;
    std::string _command;
    int _varCount;
    Variable *_var;

    int _WhereIsVar(const std::string &name) const;
    Variable *_SetVariable(const std::string &name);
    void _AddVar();
    void _ExecCommand();
    void _ParseCommand();
    void _ReadCommand();
};
