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
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"corror1",
  "west" : __DIR__"hotel1",
  "south" : __DIR__"corror3",
]));

        setup();
        create_door("west", "ľ����", "east", DOOR_CLOSED);
}
