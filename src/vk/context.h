#ifndef CONTEXT_H
#define CONTEXT_H

class CGraphicsContext
{
private:
    /**
     * @brief Window handle, passed from constructor.
     * 
     */
    void* m_pWindow;
public:
    /**
     * @brief Context constructor. Initializes context for the window whose handle is passed.
     * 
     * @param handle 
     */
    CGraphicsContext(void* handle);

    /**
     * @brief De-init the context.
     * 
     */
    ~CGraphicsContext();

    /**
     * @brief Swap the buffers of the window.
     * 
     */
    void Swap();
};

#endif