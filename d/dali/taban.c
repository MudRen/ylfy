inherit ROOM;
void create()
{
        set("short", "����̤��");
        set("long", @LONG
������ǰ��һ���޴��˫��ľ����������Φ�޷�����Ȼ�ǳ���ͣ���������
�ϵƻ�ͨ�����������С�΢�紵����ϸ�����ϣ������н���ġ�žž����������Ҳ
��֮΢��΢����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lastbridge",
  "south" : __DIR__"boat",
]));
        set("outdoors","dali");

        setup();
}
