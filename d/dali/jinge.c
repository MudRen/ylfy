inherit ROOM;
void create()
{
        set("short", "���߸�");
        set("long", @LONG
�˸��޶���ÿ����ҹ��΢��ϮϮ�����ǵ�㣻һ�����£��������롣����������
����Ǿ����۵ס���񷰵����Ψ����һյ�����ﾡ����ΨӢ�����ˡ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"secfloor",
]));


        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/lishishi" : 1,
]));
        set("outdoors","dali");
        setup();
}
