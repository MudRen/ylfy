inherit ROOM;
#include <room.h>
void create()
{
        set("short", "����");
        set("long", @LONG
ÿ���岽�����Ҹ�һ�š��������мǺţ��ź�����������ÿ��ʮ�������һյ��
��������������ϸ�������ƺ�ÿ���տա�����������������ǰ��չ��һ����������
ͷ��ÿ�������沨ҡ�ڣ��������εĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"corror2",
  "east" : __DIR__"hotel2",
]));

        setup();
        create_door("east", "ľ����", "west", DOOR_CLOSED);
}
