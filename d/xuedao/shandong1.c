// shandong1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ��");
        set("long",@LONG
�տյ���һ��ɽ������Ҳ����ɾ�����ͷ����һ��ʯ����
LONG );
        set("sleep_room",1);
          set("no_quit",1);
        set("exits",([
                  "out" : __DIR__"sroad8",
        ]));
        set("objects", ([
                __DIR__"obj/dachang" :1,
        ]));
        setup();
        replace_program(ROOM);
}

