inherit ROOM;
void create()
{
        set("short", "�����۴���");
        set("long", @LONG
��ľ�հ屻���������֡�ǽ�����ܹ����˵������˵�����ử������һ�Ŵ��
��̺���������ɷ�Բ������ɴ�����ʵ�������Ů���������衣�е�����
[1;31m
                        �������¶ӯӯ��
                        ��Ⱦ��֬һ���ᡣ
[2;37;0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"boat3",
  "south" : __DIR__"wting",
  "north" : __DIR__"eting",
  "westup"   : __DIR__"stairs",
]));

       set("objects", ([
        __DIR__"npc/dancer" : 3,
                        ]) );

        setup();
}
