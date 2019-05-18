//
// Created by shiqing on 18-10-9.
//

#include "GbkText.h"


GbkText::GbkText(string path) : Text(path) {

}

GbkText::~GbkText(void) {

}

bool GbkText::ReadOneChar(string &oneChar) {

    // return true 表示读取成功，
    // return false 表示已经读取到流末尾
    if (m_length == m_index)
        return false;
    if ((unsigned char) m_binaryStr[m_index] < 0x81) {
        oneChar = m_binaryStr[m_index];
        m_index++;
    } else {
        oneChar = string(m_binaryStr, 2);
        m_index += 2;
    }
    return true;
}
