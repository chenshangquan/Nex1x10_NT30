#ifndef __NIPDEBUG_NIPDEBUG_H__
#define __NIPDEBUG_NIPDEBUG_H__
#include <signal.h>

#define NO_SYMBOL_BT_SIZE 4	/* elf�޷��ţ���û��ָ�������ļ�����û��ָ����СʱĬ�ϴ�ӡ��ջ��С */
#ifdef __cplusplus
extern "C"{
#endif

/* 
 * ˵����btsize�����ʾ���ݸ�����Ϊ0���ҵ�main����Ϊֹ
 * 	 symbol_file�Ƿ����ļ�����ִ���ļ�����������ű�ʱ����Դ˲�����
 *	 crushdump_file�ǳ����쳣������ļ���Ϊ�ջ����������̨
 *	 signum�ź�id
 * ʾ����init_nipdebug(0,  NULL, NULL);
 *	 init_nipdebug(10, NULL, "/usr/cursh.out");
 *	 init_nipdebug(0,  "/bin/ebt.sym", "/usr/cursh.out");
 *	 init_nipdebug2(SIGPIPE,  "/bin/ebt.sym", "/usr/cursh.out");
 */
int init_nipdebug(int btsize, const char *symbol_file, const char *crushdump_file);
int init_nipdebug2(int signum, int btsize, const char *symbol_file, const char *crushdump_file);

#ifdef __cplusplus
}
#endif
#endif

