inherit ROOM;
void create()
{
        set("short", "���Ͼ�");
        set("long", @LONG
���Ͼƣ��������延��
̴���������׻����������������������۰��࿴��
���������޷�̡�
���Ϸ����ɰ���������ؾ��п��������尲��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hua",
  "northeast" : __DIR__"shui",
]));

        setup();
}
