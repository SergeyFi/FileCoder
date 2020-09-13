#pragma once
#include <memory>

#include "Parser/Parser.h"
#include "CommandHolder/CommandHolder.h"
#include "Executor/Executor.h"
#include "Coder/Coder.h"

#include "Commands/CommandVersion.h"
#include "Commands/CommandEncode.h"
#include "Commands/CommandDecode.h"

static std::shared_ptr<IParser> Parser {new class Parser()};
static std::shared_ptr<ICommandHolder> CommandHolder {new class CommandHolder()};
static std::shared_ptr<IExecutor> Executor {new class Executor(CommandHolder.get())};
static std::shared_ptr<ICoder> Coder {new class Coder()};

void Init()
{
    CommandHolder->AddCommand<CommandVersion>("version", "0.1a-3");
    CommandHolder->AddCommand<CommandEncode>("encode", Coder.get());
    CommandHolder->AddCommand<CommandDecode>("decode", Coder.get());
}