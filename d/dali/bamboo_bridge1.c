inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����Ͻ���Ǿޱ��ľ�㡢��÷����ȸ�������������ɡ����ڡ�������֡�������
���桢�ٺϡ������ޡ������ޡ����ؽ�����֦ĵ�����࣬����ö�١�������֮ʱ����
���������Զ�����ߣ���ֲ������ݡ�һ��δл��һ���ֿ���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"garden",
  "southeast" : __DIR__"bamboo_bridge2",
]));

        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/gongzi" : 1,
]));
        set("outdoors","dali");

        setup();
}
