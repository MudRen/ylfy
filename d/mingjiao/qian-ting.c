// Room: qian-ting.c

inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
�ϵ�ɽ����һ����˹���Ľ�����Ȼ�����������ǰ������ɫ��
�����ߺͽ��ɫ�������໥��ӳ�������������ڷ��⣬���������߾�
̾���ѣ���ǰ����ʯ���Ͽ������������֣����������״���㲻��
��������������Щһ�����̹������ķ�ɡ�����ʶ�ؼӿ��˽Ų���

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"guangming-ding",
  "southwest" : __DIR__"xiaolu-1",
]));
        set("objects", ([
                __DIR__"npc/pengyingyu" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

