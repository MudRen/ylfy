inherit ROOM;
void create()
{
        set("short", "����Ů");
        set("long", @LONG
����Ů����ѡ����ӯ��
�̺�է�����£��ཫ���ǲ����ˣ��峪áƵƵ��
���ںã���Ϸ������
��������ž�ҹ��̤�භ�����ഺ��������Ⱥ�档
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xue",
  "west" : __DIR__"lastbridge",
]));

        setup();
        replace_program(ROOM);
}
