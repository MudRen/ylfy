#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
����һ��С����, ��Ȼ����, ���ǹ���ư��, ���ν���, ������ȫ����̨
�϶��������ʹϹ��߲�, �����Ϻ, �������಻��, ��ʮ�ָɾ����롣
long);
         set("objects", ([
             __DIR__"obj/longjing-caiyeji" : 1,
             __DIR__"obj/meihua-zaoya" : 1,
]));
         set("exits",([
             "west" : __DIR__"c14-3",
]));
         setup();
         
}
