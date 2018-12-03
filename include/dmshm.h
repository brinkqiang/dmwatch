
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DMSHM_H_INCLUDE__
#define __DMSHM_H_INCLUDE__

#include <dmos.h>
#include <dmtypes.h>
/**
* @brief �����ڴ�Ľṹ��
*
*/
struct DMShmem
{
    DMHANDLE    handle;		/**<�ļ���Ӧ��handle*/
    uint8_t *   mem;		/**<�����ڴ����ʼ��ַ*/
    std::string file;		/**<�����ڴ��Ӧ���ļ�·��*/
};

/**
* @brief �����ļ��нṹ
*
*/
struct DMShmConfig
{
    std::string name;       /**<�����ڴ������*/
    int bufsize;            /**<�����ڴ浥���ֽ���*/
    int bufcount;           /**<�����ڴ��������*/
};


/**
* @brief
* ��һ�������ڴ�
* @param pszFileName : �����ڴ�ӳ���ļ�
* @param bCreate : ���û�иù����ڴ�ʱ���Ƿ񴴽������ڴ�
* @param size : �����ڴ��С
* @return �����ڴ�Ľṹ��
*/
DMShmem DMAPI DMOpenShmem( const char * pszFileName, bool bCreate = false, uint32_t size = 0 );

/**
* @brief
* ����һ�������ڴ�
* @param pszFileName : �����ڴ�ӳ���ļ�
* @param size : �����ڴ��С
* @return �����ڴ�Ľṹ��
*/
DMShmem DMAPI DMCreateShmem( const char * pszFileName, uint32_t size );

/**
* @brief
* ����һ�������ڴ�
* @param file : �����ڴ�ӳ���ļ�
* @param size : �����ڴ��С
* @return �����ڴ�Ľṹ��
*/
bool DMAPI DMShmemExist( const char * pszFileName );

/**
* @brief
* �ر�һ�������ڴ�
* ��windows����ϵͳ�У�����򿪴������ڹرմ������ڴ潫������
* ��linux����ϵͳ�У� ��ֱ�ӱ�����
* @param shm : �����ڴ�Ľṹ��
* @return void
*/
void DMAPI DMCloseShmem( DMShmem * shm );

/**
* @brief
* ����һ�������ڴ���
*/
class CDMShmem
{
public:
    CDMShmem();

    /**
    * @brief
    * ��һ�������ڴ�
    * @param pszFileName : �ļ�·��
    * @return ָ�����ڴ��ָ��
    */
    void * DMAPI Open( const char * pszFileName );

    /**
    * @brief
    * ����һ�������ڴ�
    * @param pszFileName : �ļ�·��
    * @param size : �ļ���С
    * @return ָ�����ڴ��ָ��
    */
    void * DMAPI Create( const char * pszFileName, uint32_t size );

    /**
    * @brief
    * �رչ����ڴ�
    * @return void
    */
    void DMAPI Close();

    /**
    * @brief
    * ��ȡ�����ڴ���
    * @return �����ڴ���
    */
    DMHANDLE GetHandle();

private:
    DMShmem m_shm;
};

#endif // __DMSHM_H_INCLUDE__
