//by guoguo
int main(object me,string arg)
{
    object room = environment(me);
    mapping exits;
    string *outs,dir;
    if(!room || !objectp(room) || !room->query("short"))
    {
        return notify_fail("�㱻��ס�ˡ�\n");
    }
    exits = room->query("exits",1);
    if(!mapp(exits) || sizeof(exits)==0)
    {
        return notify_fail("����û�г��ڡ�\n");
    }
    outs = keys(exits);
    dir = "go "+outs[random(sizeof(outs))];
    me->command(dir);
    return 1;
}