#include <net/daemons.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
   if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
   write("���ʻ����Ѿ��رգ� �򿪻�������update dns_master\n");
   return 1;
}
