inherit ROOM;
void create()
{
          set("short", "�쾮");
        set("long", @LONG
������ͨ�԰�����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м�
�����Ų���ľ�ˡ�ʮ��������������ϰ���ա��ϱ�����������
LONG
        );
        set("exits", ([
                "north" : __DIR__"xiefj",
                "south" : __DIR__"yishi",
                  "west" : __DIR__"sleep_room",
                  "east" : __DIR__"weapon_room",
        ]));
        set("objects", ([
     "/d/shaolin/npc/mu-ren" : 10,
        ]));
        set("outdoors", "city");
        setup();
        replace_program(ROOM);
}
