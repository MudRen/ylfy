#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","��Ժ");
         set ("long",@long
����һ�������εĹ���, ������һ��С¥֮ǰ��С¥����һ���Ҷ�, д
��: "�ƽ�¥" ����ī�̺���, ¥��ǰ�������ֵĶ��ǲ軨������Щ�軨
����������������ɫ, ���⾫�µ�¥��ͤ����, δ�ⲻ�ġ���������
һ�����ȣ��������ƽ�¥��
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"yunjinlou",
             "west" : __DIR__"c13",
             "east" : __DIR__"c14-2",
             "north" : __DIR__"xiaojing8",
]));
         setup();
         replace_program(ROOM);
}
