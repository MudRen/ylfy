inherit ROOM;
void create()
{
    set("short", RED "                     ԡѪ����"NOR);
    set("long","                "+HIR+"Ϧ     ��"+NOR+RED+"
�ѽ���������Ⱦ��Ѫ��ɫ����·����ᵽһ��Ѫ��֮����"+NOR+"\n ");
    set("exits", ([ /* sizeof() == 1 */
]));
    set("no_magic", 1);
    set("fight_room", __DIR__"biwu4");
    setup();
}
void relay_message(string msg)
{
    object look_fight_room;
   string *msgs;
    int i;
    if (!look_fight_room=find_object(__DIR__"biwu4"))
    look_fight_room=load_object(__DIR__"biwu4");
   msgs=explode(msg, "\n");
    for (i=0;i<sizeof(msgs);i++)
    if (strlen(msgs[i])>5)
    message("vision",NOR+BOLD+">>"+NOR+msgs[i]+"\n",look_fight_room);
}

