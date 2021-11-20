window.addEventListener('DOMContentLoaded',function(){
    var div = document.querySelector('div');
    var span = document.querySelector('span');
    var btn = document.querySelector('button');
    //console.log(div.offsetLeft);
    function animate(obj,target){
        //console.log('running');
        clearInterval(obj.timer);

        temp[flag++] = obj.timer = setInterval(function(){
            //console.log(obj.offsetLeft);           
            if(obj.offsetLeft >= target){
                console.log('timer'+obj.timer);
                console.log('temp:' + temp);
                clearInterval(obj.timer);

            }else{
                obj.style.left = obj.offsetLeft + 1 + 'px';
                //console.log('last'+span.offsetLeft);
            }
        },30);
    }
    //animate(div,300);
    function fn(){
        alert(span.offsetLeft);
    }
    //bind 这里还缺少引用以便于解绑 你妈 坑好多 傻逼js
    btn.addEventListener('click',animate.bind(this,span,50,false));
    
})