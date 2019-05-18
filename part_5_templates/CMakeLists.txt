
set(TemplateBase
        UsefullFwd.h
        FunctionTemplates.cpp
        ClassTemplates.cpp
        NoneTypeParametersTemplate.cpp
        BaseTechniqueTemplate.cpp
        ActionTemplate.cpp
        TermTemplate.cpp
        DeepBaseTemplate.cpp
        NamesOfTemplate.cpp
        InstantiationTemplate.cpp
        StaticPolymorphismTemplate.cpp
        TraitAndPolicyTemplate.cpp
        InheritanceTemplate.cpp
        MetaProgrammingTemplate.cpp
        ExpressionTemplate.cpp
        TypeDistinctionTemplate.cpp
        HolderAndTrupleTemplate.cpp
        TupleTemplate.cpp
        FunctionObjAndCallback.cpp
        )


add_library(Template ${TemplateBase})

add_executable(FunctionTemplate FunctionTemplates.cpp)
add_test(NAME FunctionTemplate COMMAND FunctionTemplate)

add_executable(ClassTemplate ClassTemplates.cpp)
add_test(NAME ClassTemplate COMMAND ClassTemplate)

add_executable(NoneTypeParametersTemplate NoneTypeParametersTemplate.cpp)
add_test(NAME NoneTypeParametersTemplate COMMAND NoneTypeParametersTemplate)

add_executable(BaseTechniqueTemplate BaseTechniqueTemplate.cpp)
add_test(NAME BaseTechniqueTemplate COMMAND BaseTechniqueTemplate)

add_executable(ActionTemplate ActionTemplate.cpp)
add_test(NAME ActionTemplate COMMAND ActionTemplate.cpp)

add_executable(TermTemplate TermTemplate.cpp)
add_test(NAME TermTemplate COMMAND TermTemplate.cpp)

add_executable(DeepBaseTemplate DeepBaseTemplate.cpp)
add_test(NAME DeepBaseTemplate COMMAND DeepBaseTemplate.cpp)

add_executable(NamesOfTemplate NamesOfTemplate.cpp)
add_test(NAME NamesOfTemplate COMMAND NamesOfTemplate.cpp)

add_executable(InstantiationTemplate InstantiationTemplate.cpp)
add_test(NAME InstantiationTemplate COMMAND InstantiationTemplate.cpp)

add_executable(StaticPolymorphismTemplate StaticPolymorphismTemplate.cpp)
add_test(NAME StaticPolymorphismTemplate COMMAND StaticPolymorphismTemplate.cpp)

add_executable(TraitAndPolicyTemplate TraitAndPolicyTemplate.cpp)
add_test(NAME TraitAndPolicyTemplate COMMAND TraitAndPolicyTemplate.cpp)


add_executable(InheritanceTemplate InheritanceTemplate.cpp)
add_test(NAME InheritanceTemplate COMMAND InheritanceTemplate.cpp)

add_executable(MetaProgrammingTemplate MetaProgrammingTemplate.cpp)
add_test(NAME MetaProgrammingTemplate COMMAND MetaProgrammingTemplate.cpp)

add_executable(ExpressionTemplate ExpressionTemplate.cpp)
add_test(NAME ExpressionTemplate COMMAND ExpressionTemplate.cpp)

add_executable(TypeDistinctionTemplate TypeDistinctionTemplate.cpp)
add_test(NAME TypeDistinctionTemplate COMMAND TypeDistinctionTemplate.cpp)

add_executable(HolderAndTrupleTemplate HolderAndTrupleTemplate.cpp)
add_test(NAME HolderAndTrupleTemplate COMMAND HolderAndTrupleTemplate.cpp)

add_executable(TupleTemplate TupleTemplate.cpp)
add_test(NAME TupleTemplate COMMAND TupleTemplate.cpp)

add_executable(FunctionObjAndCallback FunctionObjAndCallback.cpp)
add_test(NAME FunctionObjAndCallback COMMAND FunctionObjAndCallback.cpp)


