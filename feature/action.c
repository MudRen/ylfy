// action.c

#include <function.h>
nosave mixed busy, interrupt;
varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	object ob;
	// �ռ�boss����busyӰ��
	if ( this_object()->query("end_boss", 1) )
	{
		busy = 0;
		return;
	}
    if( !new_busy ) 
	{
		busy=0;
		return;
	}
    if( !intp(new_busy) && !functionp(new_busy) )
        error("action: Invalid busy action type.\n");
    // Add Start---
	ob = previous_object();
	if ( ob 
		&& sscanf(base_name(ob), "%*skungfu/skill/%*s") 
		&& new_busy > 30 )
		busy = 30 + random(30);
	else
	// Add End---
		busy = new_busy;
    if( !intp(new_interrupt) && !functionp(new_interrupt) )
        error("action: Invalid busy action interrupt handler type.\n");  
    interrupt = new_interrupt;  
    set_heart_beat(1);
}
nomask mixed query_busy() {
 return busy;
 }
nomask int is_busy() {
 return busy!=0;
 }
// This is called by heart_beat() instead of attack() when a ppl is busy
// doing something else.
void continue_action()
{
    if( intp(busy) && (busy > 0) ) {
        busy--;
        return;
    } else if( !( functionp(busy) & FP_OWNER_DESTED )) {
        if( !evaluate(busy, this_object()) ) {
            busy = 0;
            interrupt = 0;
        }
    } else {
        busy = 0;
        interrupt = 0;
    }
}
void interrupt_me(object who, string how)
{
    if( !busy ) return;
    if( intp(busy) && intp(interrupt) ) {
        if( busy < interrupt ) busy = 0;
    } else if( !( functionp(interrupt) & FP_OWNER_DESTED) ) {
        if( evaluate(interrupt, this_object(), who, how) ) {
            busy = 0;
            interrupt = 0;
        }
    }
}
// This function is for temporary conditions's recovery call_outs, bcz
// such recovery function call_out might be destroyed if some wizard
// destructed the object that is reponsible of it, so we let users launch
// the call_out themself. Thus we can make sure the recovery call_out.
// 
// Because this could cause a serious security problem, so we need highest
// security check here.
/*int start_call_out(function fun, int delay)
{
    if( !previous_object()
    ||  (geteuid(previous_object()) != ROOT_UID
         && userp(this_object())
         && this_player(1) != this_object()))
        return 0;
    call_out("eval_function", delay, fun);
    return 1;
}
protected void eval_function(function fun) {
    if( (functionp(fun) & FP_OWNER_DESTED) )
       return;
 evaluate(fun);
 }*/

int start_call_out(function fun, int delay)
{
        if (wiz_level(this_object()) > 0 || 1)
                // I won't bind the function because it will
                // cause a serious security problem.
                call_out("eval_function", delay, fun);
        else
                // if this_object() doesn't be a wizard, I will
                // bind the function, then the player doesn't
                // occur error when the function's owner be
                // destructed.
                call_out("eval_function", delay, bind(fun, this_object()));
        return 1;
}

protected void eval_function(function fun) 
{
        evaluate(fun);
}