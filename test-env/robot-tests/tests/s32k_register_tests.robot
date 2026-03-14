*** Settings ***
Library           CSVLibrary
Library           ../resources/S32K144GdbLibrary.py
Library           Collections

*** Variables ***
${CSV_FILE}       ${CURDIR}/test_cases.csv

*** Test Cases ***
Run S32K144 Register Tests From CSV
    [Documentation]    Reads test cases from CSV and validates register read/write on S32K144
    ${test_cases}=    Read CSV File To Associative    ${CSV_FILE}
    FOR    ${row}    IN    @{test_cases}
        ${in_addr}=     Get From Dictionary    ${row}    input_address
        ${in_val}=      Get From Dictionary    ${row}    input_value
        ${out_addr}=    Get From Dictionary    ${row}    output_address
        ${exp_val}=     Get From Dictionary    ${row}    expected_value
        Log    Writing ${in_val} to ${in_addr}
        Write Register    ${in_addr}    ${in_val}
        ${actual}=    Read Register    ${out_addr}
        Should Be Equal    ${actual}    ${exp_val.lower()}
        ...    msg=FAIL: ${out_addr} expected ${exp_val} but got ${actual}
        Log    PASS: ${out_addr} = ${actual}
    END
