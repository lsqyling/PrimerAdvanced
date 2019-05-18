//
// Created by shiqing on --.
//

#include "Text.h"

Text::Text(string path) : m_index() {
    filebuf *pbuf;
    ifstream filestr;
    // 采用二进制打开
    filestr.open(path.c_str(), ios::binary);
    if (!filestr) {
        cerr << path << " Load text error." << endl;
        return;
    }
    // 获取filestr对应buffer对象的指针
    pbuf = filestr.rdbuf();
    // 调用buffer对象方法获取文件大小
    m_length = (int) pbuf->pubseekoff(0, ios::end, ios::in);
    pbuf->pubseekpos(0, ios::in);
    // 分配内存空间
    m_binaryStr = new char[m_length + 1];
    // 获取文件内容
    pbuf->sgetn(m_binaryStr, m_length);
    //关闭文件
    filestr.close();
}

void Text::SetIndex(size_t index) {
    m_index = index;
}

size_t Text::Size() {
    return m_length;
}

Text::~Text() {
    delete[] m_binaryStr;
}

