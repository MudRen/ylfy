inherit ROOM;
void create()
{
        set("short", "����");
        set("long",@LONG
���������еķ��С�
LONG
        );

        set("exits", ([
                "east": __DIR__"qianzhuang",
                ]));

        set("objects", ([
//         "/d/city/npc/chefu.c":1,	
                ]) );

        setup();
        set("valid_startroom", 1);
        replace_program(ROOM);
}
